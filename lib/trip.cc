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

void Trip::setNextStopTime(StopTimeList::const_iterator next) {
  if (next != stoptimes.end()) {
    nextStopTime = (*next);
  } else {
    nextStopTime = NULL;
  }
}

// Load the Path in from the static path class
void Trip::loadPath() {
  currentPath = Paths::getPath(shapeId);
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
}

// Destructor
Trip::~Trip() {

}

// Get the being time and end time for the trip
// This information comes from the stop_times
void Trip::getBeginAndEndTime() {
  // Vector to store the information
  StopTimeList stoptimes;

  // Query the database
  queryResult myResult = DataBase::executeQuery("SELECT id,arrival_time,departure_time,stop_id,stop_sequence,pickup_type,drop_off_type FROM stop_times WHERE id='"+tripId+"'");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      StopTime *stopTime = new StopTime(c);
      stoptimes.push_back (stopTime);
    }
  }

  // Sort the vector on sequence number to ensure it is in order
  sort(&(*stoptimes.begin()), &(*stoptimes.end()));

  // Get the first stop and the last stop
  beginTime = stoptimes[0];
  endTime = (stoptimes[stoptimes.size()-1]);

  // Get the calendar and the calendar dates for the trip
  getCalendarForTrip();
  getCalendarDatesForTrip();

  // Free the vector
  vector<StopTime*>().swap(stoptimes);

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
    if (currentTime >= nextStopTime->getArrivalTime()) {
      StopTimeList::iterator it = find(stoptimes.begin(),stoptimes.end(),nextStopTime);
      if (it != stoptimes.end()) {
        currentStopTime = nextStopTime;
        nextStopTime = (*it);
      }
    }
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
  time_t currentTime = Utils::getLocalTime();
  for (StopTimeList::const_iterator c = stoptimes.begin(); c != stoptimes.end(); ++c) {
    time_t stopTimeStartTime = (*c)->getArrivalTime();
    time_t stopTimeEndTime = (*c)->getDepartureTime();
    if (stopTimeStartTime < currentTime && stopTimeEndTime > currentTime) {
      currentStopTime = (*c);
      Stop *currentStop = Stops::getStop(currentStopTime->stopId);
      currentStopPoint = currentPath->getPathElementForStop(currentStop->getLocation(), currentPath->pathElements.begin(), direction);
      delete currentStop;
      if (c+1 != stoptimes.end()) {
        nextStopTime = (*(c+1));
        Stop *nextStop = Stops::getStop(nextStopTime->stopId);
        nextStopPoint = currentPath->getPathElementForStop(nextStop->getLocation(), currentStopPoint, direction);
        delete nextStop;
      }
      break;
    }
  }
}

// Start the Trip at the beginning
void Trip::start() {
  currentStopTime = (*stoptimes.begin());
  Location *startLocation;
  startLocation->latitude = -1;
  startLocation->longitude = -1;
  currentStopPoint = currentPath->getPathElementForStop(startLocation, currentPath->pathElements.begin(), direction);
  StopTimeList::const_iterator next = stoptimes.begin()+1;
  if (next != stoptimes.end()) {
    nextStopTime = (*next);
    Stop *nextStop = Stops::getStop(nextStopTime->stopId);
    nextStopPoint = currentPath->getPathElementForStop(nextStop->getLocation(), currentStopPoint, direction);
    delete nextStop;
  }
}

// Get the current location of the bus on this trip
Location* Trip::getCurrentLocationOnTrip() {
  // TODO need to add something here
  return NULL;
}
