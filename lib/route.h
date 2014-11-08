#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"

using namespace std;
using namespace pqxx;

class Route {
  public:
    string id;
    string shortName;
    string longName;
    string desc;
    int type;
    Route(string, string, string, string, int);
    Route(result::const_iterator);
    ~Route();
};

#endif
