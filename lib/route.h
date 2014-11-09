#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"
#include "trip.h"

using namespace std;
using namespace pqxx;

class Route {

  private:
    typedef vector<Trip*> TripList;
    static TripList trips;
    static bool deleteAll( Trip* trip ) { delete trip; return true; };

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

};

#endif
