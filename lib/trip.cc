#include "trip.h"

// Notes about Trips
// route_id -> This is linked to the routes, and many trips will have the same route_id
// service_id -> This is linked to calendar dates which tells up what day the route will be active
// trip_id -> This is the unique to the trip
// shape_id -> This is linked to the shape of the route, which is a list of GPS locatiions that define the route

// Trip Constructor
Trip::Trip (string _routeId, string _serviceId, string _tripId, string _tripHeadSign, string _directionId, string _blockId, string _shapeId) {
  routeId = _routeId;
  serviceId = _serviceId;
  tripId = _tripId;
  tripHeadSign = _tripHeadSign;
  directionId = _directionId;
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

  // Get the directionId if the value is not null
  if (c[4].is_null()) {
    directionId = "";
  } else {
    directionId = c[4].as<string>();
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
  queryResult myResult = DataBase::executeQuery("SELECT * FROM stop_times WHERE trip_id='"+tripId+"'");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      StopTime *stopTime = new StopTime(c);
      stoptimes.push_back (stopTime);
    }
  }

  // Sort the vector on sequence number to ensure it is in order
// TODO we will want to get this sort working at some point
//  sort(&(*stoptimes.begin()), &(*stoptimes.end()), less_than_key());

  // Get the first stop and the last stop
 beginTime = stoptimes[0];
 endTime = (stoptimes[stoptimes.size()-1]);

  // Free the vector
  vector<StopTime*>().swap(stoptimes);
}

string Trip::getBeginTime() {
  return beginTime->arrival_time;
}

string Trip::getEndTime() {
  return endTime->arrival_time;
}
