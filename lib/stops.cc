#include "stops.h"

vector<Stop*> Stops::stops;

void Stops::loadStops() {
  // Get the stops from the database
  queryResult myResult = DataBase::executeQuery("SELECT id,name,stop_desc,lat,long,street,city,region,postcode,country,zone_id FROM stops");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Stop *stop = new Stop(c);
      stops.push_back (stop);
    }
  }
}

Stop* Stops::getStop(string stopId) {
  Stop *stop = new Stop(stopId);
  StopList::iterator it = find(stops.begin(), stops.end(), stop);
  if (it != stops.end()) {
    return (*it);
  }
  return NULL;
}

void Stops::clearStops() {
  StopList().swap(stops);
}
