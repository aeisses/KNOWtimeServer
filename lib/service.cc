#include "service.h"

void Service::startService() {
  // Start the service

  // We need to get the routes
  queryResult myResult = DataBase::executeQuery("SELECT * FROM routes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      cout << "ID = " << c[0].as<string>() << endl;
      cout << "ShortName = " << c[1].as<string>() << endl;
      cout << "LongName = " << c[2].as<string>() << endl;
    } 
  }
}
