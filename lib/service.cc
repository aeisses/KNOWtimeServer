#include "service.h"

vector<Route> Service::routes;

void Service::startService() {
  // Start the service

  // We need to get the routes
  queryResult myResult = DataBase::executeQuery("SELECT * FROM routes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Route route(c);
      route.loadTrips();
      Service::routes.push_back (route);
    } 
  }

  // Loop through the routes and get the trips
//  for (RouteList::iterator it = routes.begin(); it != routes.end(); ++it) {
//    Route *route = *it;
//    cout << "RouteId: " << route->id << endl;
    // Need to think this out a bit, trips should be in routes
//  }
}
