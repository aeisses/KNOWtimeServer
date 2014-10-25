#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>

using namespace std;

class Trip {
  public:
    string routeId;
    string serviceId;
    string tripId;
    string tripHeadSign;
    string directionId;
    string blockId;
    string shapeId;
    Trip(string, string, string, string, string, string, string);
};

#endif
