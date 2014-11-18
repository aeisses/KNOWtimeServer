#include "service.h"

vector<Route*> Service::routes;

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
  queryResult myResult = DataBase::executeQuery("SELECT * FROM routes");
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
//  for (RouteList::iterator it = routes.begin(); it != routes.end(); ++it) {
//    Route *route = ;
//    cout << "RouteId: " << route->id << endl;
    // Need to think this out a bit, trips should be in routes
//  }
}
