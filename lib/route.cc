#include <route.h>


// Private Methods
void Route::determineActiveTrips() {
  time_t currentTime = Utils::getLocalTime();
  for (TripList::const_iterator it = trips.begin(); it != trips.end(); ++it) {
    if ((*it)->getBeginTime() <= currentTime && (*it)->getEndTime() >= currentTime) {
      (*it)->monitorTrip( this );
      cout << "Monitoring Trip" << endl;
      activeTrips.push_back ((*it));
    }
  }
}

void Route::determineNextTrip() {
  time_t currentTime = time(0);
  for (TripList::const_iterator it = trips.begin(); it != trips.end(); ++it) {
    if ((*it)->getBeginTime() >= currentTime && (nextTrip == NULL || nextTrip->getBeginTime() < (*it)->getBeginTime())) {
      nextTrip = (*it);
    }
  }
}

// Public Methods
Route::Route (result::const_iterator c) {

  // Get the id if the value is not null
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }

  // Get the shortName if the value is not null
  if (c[1].is_null()) {
    shortName = "";
  } else {
    shortName = c[1].as<string>();
  }

  // Get the longName if the value is not null
  if (c[2].is_null()) {
    longName = "";
  } else {
    longName = c[2].as<string>();
  }

  // Get the desc if the value is not null
  if (c[3].is_null()) {
    desc = "";
  } else {
    desc = c[3].as<string>();
  }

  // Get the type if the value is not null
  if (c[4].is_null()) {
    type = 0;
  } else {
    type = c[4].as<int>();
  }
}

Route::Route (string _id, string _shortName, string _longName, string _desc, int _type) {
  id = _id;
  shortName = _shortName;
  longName = _longName;
  desc = _desc;
  type = _type;
}

// Load the trips for this route
void Route::loadTrips() {
  // Get the trips for this route
  queryResult myResult = DataBase::executeQuery("SELECT * FROM trips WHERE route_id='"+id+"'");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Trip *trip = new Trip(c);
      trip->getBeginAndEndTime();
      trips.push_back (trip);
      cout << "Trip Loaded" << endl;
    }
  }
  determineActiveTrips();
}

// Destructor
Route::~Route() {
  TripList().swap(trips);
}

// Create a couple callbacks here that will fire from the trip class
void Route::tripCompleted(Trip *trip) {
  // Remove the trip from the activetTrips list
 cout << "Removed Trip" << endl; 
}


