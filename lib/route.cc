#include <route.h>

vector<Trip*> Route::trips;

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
      Route::trips.push_back (trip);
    }
  }
}

// Destructor
Route::~Route() {
  vector<Trip*>().swap(trips);
}
