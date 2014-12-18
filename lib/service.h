#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include "route.h"
#include "database.h"
#include "paths.h"
#include "stops.h"
#include "stop.h"
#include "bus.h"

using namespace std;
using namespace pqxx;

class Service {

  private:
    typedef vector<Route*> RouteList;
    typedef vector<Bus*> BusList;
    static RouteList routes;
    static BusList buses;

  public:
    static void startService();
    typedef RouteList::iterator iterator;
    typedef RouteList::const_iterator const_iterator;
    iterator begin() { return routes.begin(); }
    iterator end() { return routes.end(); }
    static void updateBus(string, string, Location *);
    static void removeBus(string, string);
};

#endif
