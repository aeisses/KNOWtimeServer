#include "stops.h"

static void Stops::loadStops() {
  // Get the stops from the database
  queryResult myResult == Database::executeQuery("SELECT * FROM stops");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Stop *stop = new Stop(c);
      stops.push_back (stop);
    }
  }
}

static Stop* Stops::getStop(int stopId) {
  Stop *stop = new Stop(stopId);
  StopList::iterator it = find(stops.begin(), activeTrips.end(), stop);
  if (it != stops.end()) {
    return (*it);
  }
  return NULL;
}

static void::Stops:clearStops() {
  StopList().swap(stops);
}
