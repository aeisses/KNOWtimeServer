#include "service.h"

vector<Route*> Service::routes;
vector<Bus*> Service::buses;

void Service::startService() {
  // Start the service

  // Load the stops
  cout << "Load stops" << endl;
  Stops::loadStops();
  cout << "Finished loading stops" << endl;

  // Load the paths
  cout << "Load paths" << endl;
  Paths::loadPaths();
  cout << "Finished loading paths" << endl;

  // We need to get the routes
  queryResult myResult = DataBase::executeQuery("SELECT id,short_name,long_name,route_desc,type FROM routes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Route *route = new Route(c);
      cout << "Loading Route: " << route->id << endl;
      route->loadTrips();
      Service::routes.push_back (route);
      cout << "Finished Route: " << route->id << endl;
    } 
  }

  // We want to run one timer, and run everything off the timer. The timer will execute every second

  // Loop through the routes and get the trips
  int i = 0;
  while (i<5) {
    cout << "Attempting to update Trips" << endl;
    for (RouteList::iterator it = routes.begin(); it != routes.end(); ++it) {
      cout << "RouteId: " << (*it)->id << endl;
      // Need to think this out a bit, trips should be in routes
      (*it)->updateTrips();
    }
    cout << "Finished updating the Trips" << endl;
    usleep(10000000);
    i++;
  }
}

void Service::updateBus(string tripId, string route, Location *location) {
  BusList::iterator it;
  cout << "TripId: " << tripId << " Route: " << route << endl;
  cout << "Bus two" << endl;
  cout << "BUses Size: " << buses.size() << endl;
  for (it = buses.begin(); it != buses.end(); ++it) {
    cout << "Bus two five" << endl;
    cout << "IT Route: " << (*it)->route << endl;
    cout << "IT Trip: " << (*it)->tripId << endl;
    if ((*it)->route.compare(route) == 0 && (*it)->tripId.compare(tripId) == 0) {
      cout << "Bus update location" << endl;
      (*it)->updateLocation(location);
      cout << "Bus two point five" << endl;
      break;
    }
  }
  cout << "Bus three" << endl;
  if (it == buses.end()) {
    cout << "Adding bus" << endl;
    Bus *bus = new Bus(tripId, route, location);
    cout << "Three one" << endl;
    buses.push_back(bus);
    //delete bus;
  }
  cout << "Location Lat: " << location->latitude << " Longitude: " << location->longitude << endl;
}

void Service::removeBus(string tripId, string route) {
  for (BusList::iterator it = buses.begin(); it != buses.end(); ++it) {
    if ((*it)->route == route && (*it)->tripId == tripId) {
      buses.erase(it);
      break;
    }
  }
}

//vector<Bus*> Service::getBuses {
//  return buses;
//}
