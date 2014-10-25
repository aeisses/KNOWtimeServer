#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>

using namespace std;

class Route {
  public:
    string id;
    string shortName;
    string longName;
    string type;
    Route(string, string, string, string);
};

#endif
