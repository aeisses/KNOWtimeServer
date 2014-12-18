#ifndef BUS_H
#define BUS_H

#include <string>
#include "utils.h"

using namespace std;

class Bus {
  private:

  public:
    Location *location;
    string route;
    string tripId;
    Bus(string, string, Location*);
    ~Bus();
    void updateLocation(Location*);
};

#endif
