#include "database.h"

// This value comes from Heroku
static string dbConnectString = "dbname=d6r031bbbjd94j host=ec2-54-235-250-41.compute-1.amazonaws.com port=5432 user=swynadyloypwdz password=VoIXNYM0Zfz6rMX_rtdfwfEcc- sslmode=require";

queryResult DataBase::executeQuery(string query) {

  queryResult myResult;

  try {
    // Connect to the database
    connection C(dbConnectString);
    if (C.is_open()) {
      cout << "Open database successfullt: " << C.dbname() << endl;
    } else {
      cout << "Can't open database" << endl;
      myResult.code = DB_CONNECT_FAIL;
      return myResult;
    }

    // Create a non-transactional object.
    nontransaction N(C);

    // Execute the SQL query
    result R( N.exec( query ));

    cout << "Operation done sucessfully" << endl;
    
    myResult.code = DB_SUCCESS;
    myResult.R = R;

    return myResult;

  } catch (const std::exception &e) {
    cerr << e.what() << std::endl;
    myResult.code = DB_ERROR;
    return myResult;
  }
}
