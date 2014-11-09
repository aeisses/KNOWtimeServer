#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include "route.h"
#include "database.h"

using namespace std;
using namespace pqxx;

class Service {

  private:
    typedef vector<Route*> RouteList;
    static RouteList routes;
    static vector<Trip*> trips;

  public:
    static void startService();
    typedef RouteList::iterator iterator;
    typedef RouteList::const_iterator const_iterator;
    iterator begin() { return routes.begin(); }
    iterator end() { return routes.end(); }

};

#endif
