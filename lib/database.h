#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

enum DB_RESULT_CODE {
  DB_SUCCESS,
  DB_CONNECT_FAIL,
  DB_ERROR
};

struct queryResult {
  DB_RESULT_CODE code;
  result R;
};

class DataBase {

  public:
    static queryResult executeQuery(string query);
};

#endif
