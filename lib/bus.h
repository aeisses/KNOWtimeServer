#ifndef BUS_H
#define BUS_H

#include <string>
#include <node.h>
#include "utils.h"

using namespace std;

class Bus : public node::ObjectWrap {
  private:

  public:
    Location *location;
    string route;
    string tripId;
    Bus(string, string, Location*);
    ~Bus();
    void updateLocation(Location*);
    double getLatitude();
    double getLongitude();
};

#endif
