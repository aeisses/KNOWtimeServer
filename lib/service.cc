#include "service.h"

vector<Route*> Service::routes;

void Service::startService() {
  // Start the service

  // We need to get the routes
  queryResult myResult = DataBase::executeQuery("SELECT * FROM routes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
//      cout << "ID = " << c[0].as<string>() << endl;
//      cout << "ShortName = " << c[1].as<string>() << endl;
//      cout << "LongName = " << c[2].as<string>() << endl;
//      if (!c[3].is_null()) {
//        cout << "Type = " << c[3].as<string>() << endl;
//      }
//      cout << "type = " << c[4].as<int>() << endl;

      Route *route = new Route(c);
//      Route *route = new Route(c[0].as<string>(),c[1].as<string>(),c[2].as<string>(),"",c[4].as<int>());
      Service::routes.push_back (route);
    } 
  }
}
