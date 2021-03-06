#include "trip.h"
#include "route.h"

// Notes about Trips
// route_id -> This is linked to the routes, and many trips will have the same route_id
// service_id -> This is linked to calendar dates which tells up what day the route will be active
// trip_id -> This is the unique to the trip
// shape_id -> This is linked to the shape of the route, which is a list of GPS locatiions that define the route

// Private Methods
// Get the calendar information for the trip
void Trip::getCalendarForTrip() {
  queryResult myResult = DataBase::executeQuery("SELECT id,monday,tuesday,wednesday,thursday,friday,saturday,sunday,start_date,end_date FROM calendar WHERE id='"+serviceId+"'");
  if (myResult.code == DB_SUCCESS) {
    // There should only be one result in this return vector
    if (myResult.R.size() == 1) {
      result::const_iterator c = myResult.R.begin();
      calendar = new Calendar(c);
    }
  }
}

// Get the calendarDates information for the trip
void Trip::getCalendarDatesForTrip() {
  queryResult myResult = DataBase::executeQuery("SELECT id,date,exception_type FROM calendar_dates WHERE id='"+serviceId+"'");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      CalendarDate *calendarDate = new CalendarDate(c);
      calendardates.push_back (calendarDate);
    }
  }
}

// Set the next stop time
void Trip::setNextStopTime(StopTimeList::const_iterator next) {
  if (next != stoptimes.end()) {
    nextStopTime = (*next);
  } else {
    nextStopTime = 0;
  }
}

// Load the Path in from the static path class
void Trip::loadPath() {
  currentPath = Paths::getPath(shapeId);
}

// Sort the stops by stop_sequence, the sort is not working....
bool Trip::sortBySequence(const StopTime &lhs, const StopTime &rhs) {
  return lhs.stop_sequence < rhs.stop_sequence;
}

// Public Methods
// Trip Constructor
Trip::Trip (string _routeId, string _serviceId, string _tripId, string _tripHeadSign, int _direction, string _blockId, string _shapeId) {
  routeId = _routeId;
  serviceId = _serviceId;
  tripId = _tripId;
  tripHeadSign = _tripHeadSign;
  direction = _direction;
  blockId = _blockId;
  shapeId = _shapeId;
}

// Trip Constructor
Trip::Trip (result::const_iterator c) {

  // Get the routeId if the value is not null
  if (c[0].is_null()) {
    routeId = "";
  } else {
    routeId = c[0].as<string>();
  }

  // Get the serviceId if the value is not null
  if (c[1].is_null()) {
    serviceId = "";
  } else {
    serviceId = c[1].as<string>();
  }

  // Get the tripId, it is the primary key and always has a value
  tripId = c[2].as<string>();

  // Get the tripHeadSign if the value is not null
  if (c[3].is_null()) {
    tripHeadSign = "";
  } else {
    tripHeadSign = c[3].as<string>();
  }

  // Get the direction if the value is not null
  if (c[4].is_null()) {
    direction = -1;
  } else {
    direction = c[4].as<int>();
  }

  // Get the blockId if the value is not null
  if (c[5].is_null()) {
    blockId = "";
  } else {
    blockId = c[5].as<string>();
  }

  // Get the shapeId if the value is not null
  if (c[6].is_null()) {
    shapeId = "";
  } else {
    shapeId = c[6].as<string>();
  }

  beginTime = 0;
  endTime = 0;
  nextStopTime = 0;
  currentStopTime = 0;
  calendar = 0;
  currentPath = 0;
}

// Destructor
Trip::~Trip() {
  // Free the vector
  vector<StopTime*>().swap(stoptimes);

  if (beginTime) {
    delete beginTime;
  }
  if (endTime) {
    delete endTime;
  }
  if (nextStopTime) {
    delete nextStopTime;
  }
  if (currentStopTime) {
    delete currentStopTime;
  }
  if (calendar) {
    delete calendar;
  }
  if (currentPath) {
    delete currentPath;
  }
}

// Get the being time and end time for the trip
// This information comes from the stop_times
void Trip::getBeginAndEndTime() {
  // Query the database
  queryResult myResult = DataBase::executeQuery("SELECT id,arrival_time,departure_time,stop_id,stop_sequence,pickup_type,drop_off_type FROM stop_times WHERE id='"+tripId+"'");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      StopTime *stopTime = new StopTime(c);
      stoptimes.push_back (stopTime);
    }
  }

  // Sort the vector on sequence number to ensure it is in order
  // TODO This sort is not working.... Need to look into this..... Dubs will know how to do this for now it is ok
//  sort(stoptimes.begin(), stoptimes.end());

  // Get the first stop and the last stop
  beginTime = stoptimes[0];
  endTime = (stoptimes[stoptimes.size()-1]);

  // Get the calendar and the calendar dates for the trip
  getCalendarForTrip();
  getCalendarDatesForTrip();

  // Load the path
  loadPath();
}

time_t Trip::getBeginTime() {
  return beginTime->getArrivalTime();
}

time_t Trip::getEndTime() {
  return endTime->getArrivalTime();
}

// Monitor the trip and call back when the trip ends
void Trip::monitorTrip(Route* route) {
  time_t currentTime = Utils::getLocalTime();
  if (currentTime >= getEndTime()) {
    route->tripCompleted( this );
  } else {
    // Move the trip forward
    if (currentTime >= currentStopTime->getArrivalTime()) {
      StopTimeList::iterator it;
      for (it = stoptimes.begin(); it != stoptimes.end(); ++it) {
        if (nextStopTime->stop_sequence == (*it)->stop_sequence) {
          break;
        }
      }
      if ((it+1) != stoptimes.end()) {
        currentStopTime = nextStopTime;
        nextStopTime = (*(it+1));
      } else if ((it+1) == stoptimes.end()) {
        currentStopTime = nextStopTime;
      }
    }
    Stop *currentStop = Stops::getStop(currentStopTime->stopId);
    currentStopPoint = currentPath->getPathElementForStop(currentStop->getLocation(), currentStopPoint, direction);
    Stop *nextStop = Stops::getStop(nextStopTime->stopId);
    nextStopPoint = currentPath->getPathElementForStop(nextStop->getLocation(), currentStopPoint, direction);
    cout << "CurrentStop Id: " << currentStopTime->stopId << endl;
    cout << "NextStop Id: " << nextStopTime->stopId << endl;
    cout << "---- Done moving the trip forward ----" << endl;
  }
}

// We need to check if the trip is valid on the day
bool Trip::isRunningToday() {
  // If the Calendar object does not exist, return false
  if (calendar == NULL) {
    return false;
  }

  if (!calendar->isValid()) {
    return false;
  }
  return true;
}

// Get the next and previous stoptimes
void Trip::alignToCurrentStopTime() {
  cout << "---- Aliging to current stop times ----" << endl;
  time_t currentTime = Utils::getLocalTime();
  for (StopTimeList::const_iterator c = stoptimes.begin(); c != stoptimes.end(); ++c) {
    time_t stopTimeStartTime = (*c)->getArrivalTime();
    if (c+1 != stoptimes.end()) {
      time_t stopNextTimeStartTime = (*(c+1))->getArrivalTime();
      if (stopTimeStartTime <= currentTime && stopNextTimeStartTime >= currentTime) {
        currentStopTime = (*c);
        Stop *currentStop = Stops::getStop(currentStopTime->stopId);
        currentStopPoint = currentPath->getPathElementForStop(currentStop->getLocation(), currentPath->pathElements.begin(), direction);
        if (c+1 != stoptimes.end()) {
          nextStopTime = (*(c+1));
          Stop *nextStop = Stops::getStop(nextStopTime->stopId);
          nextStopPoint = currentPath->getPathElementForStop(nextStop->getLocation(), currentStopPoint, direction);
        }
        break;
      }
    }
  }
}

// Start the Trip at the beginning
void Trip::start() {
  currentStopTime = (*stoptimes.begin());
  Location *startLocation = new Location();
  startLocation->latitude = -1;
  startLocation->longitude = -1;
  currentStopPoint = currentPath->getPathElementForStop(startLocation, currentPath->pathElements.begin(), direction);
  delete startLocation;
  StopTimeList::const_iterator next = stoptimes.begin()+1;
  if (next != stoptimes.end()) {
    nextStopTime = (*next);
    Stop *nextStop = Stops::getStop(nextStopTime->stopId);
    nextStopPoint = currentPath->getPathElementForStop(nextStop->getLocation(), currentStopPoint, direction);
  }
}

// End the trip
void Trip::end() {
  delete currentStopTime;
  delete nextStopTime;
}

// Get the current location of the bus on this trip
Location* Trip::getCurrentLocationOnTrip() {
  Location *returnLocation = new Location();
  int stopLocationDiff = abs(nextStopPoint - currentStopPoint);
  cout << "---- StopLocationDiff: " << stopLocationDiff << endl;
  if (stopLocationDiff == 0) {
    stopLocationDiff = 1;
  }
  time_t stopTimeStartTime = currentStopTime->getArrivalTime();
  time_t stopTimeEndTime = nextStopTime->getDepartureTime();
  time_t timeDiff = stopTimeEndTime - stopTimeStartTime;
//  cout << "---- TimeDiff: " << timeDiff << endl;
  time_t timeInterval = 0;
  if (timeDiff != 0) {
    timeInterval = (time_t)(timeDiff/stopLocationDiff);
    if (timeInterval == 0) {
      timeInterval = 1;
    }
  }
  time_t currentTime = Utils::getLocalTime();

  for (int i = 1; i<=stopLocationDiff; i++) {
    cout << "**** CurrentTime: " << currentTime << endl;
    cout << "**** StopTimeStartTime: " << stopTimeStartTime << endl;
    cout << "**** timeInterval: " << timeInterval << endl;
    if (((timeInterval*i) + stopTimeStartTime) > currentTime) {
      cout << "---- I: " << i << endl;
      returnLocation = (*(currentStopPoint+i-1))->getLocation();
      break;
    }
  }
//  cout << "---- Returnlocation Latitude: " << returnLocation->latitude << " Longitude: " << returnLocation->longitude << endl;
  return returnLocation;
}

bool Trip::operator== (const Trip& lhs) {
  if (lhs.tripId == this->tripId) {
    return true;
  }
  return false;
}

