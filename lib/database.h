#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>
#include <pqxx/pqxx>

using namespace std;
using namespace ppxx;

class DataBase {

  enum DB_RESULT_CODE {
    DB_SUCCESS,
    DB_CONNECT_FAIL,
    DB_QUERY_FAIL
  };

  struct queryResult {
    DB_RESULT_CODE code;
    result R;
  };
 
  public:
    static queryResult executeQuery(String query);
};

#endif
