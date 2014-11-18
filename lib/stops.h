#ifndef STOPS_H
#define STOPS_H

#include <vector>
#include <algorithm>
#include <pqxx/pqxx>
#include "database.h"
#include "stop.h"

using namespace std;
using namespace pqxx;

class Stops {

  private:
    typedef vector<Stop*> StopList;
    static StopList stops;

  public:
    static void loadStops();
    static Stop* getStop(int);
    static void clearStops();
};

#endif
