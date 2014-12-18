#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <pqxx/pqxx>
#include <algorithm>
#include "database.h"
#include "trip.h"
#include "service.h"

using namespace std;
using namespace pqxx;

class Route {

  private:
    typedef vector<Trip*> TripList;
    TripList trips;
    TripList activeTrips;
    Trip *nextTrip;
    void determineActiveTrips();
    void determineNextTrip();

  public:
    string id;
    string shortName;
    string longName;
    string desc;
    int type;
    Route(string, string, string, string, int);
    Route(result::const_iterator);
    void loadTrips();
    ~Route();
    typedef TripList::iterator iterator;
    typedef TripList::const_iterator const_iterator;
    iterator begin() { return trips.begin(); };
    iterator end() { return trips.end(); };
    void tripCompleted( Trip* );
    void watchNextTrip();
    void updateTrips();
};

#endif
