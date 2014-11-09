#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"

using namespace std;
using namespace pqxx;

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
    Trip(result::const_iterator);
    ~Trip();
};

#endif
