#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>

using namespace std;

class Path {
  public:
    string id;
    double lat;
    double lng;
    int sequence;
    Path(string, double, double, int);
};

#endif
