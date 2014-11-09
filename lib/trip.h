#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <algorithm>
#include <vector>
#include <pqxx/pqxx>
#include "database.h"
#include "stoptime.h"

using namespace std;
using namespace pqxx;

struct less_than_key {
  inline bool operator() (const StopTime i, const StopTime j) {
    return ( i.stop_sequence < j.stop_sequence );
  }
};

class Trip {

  private:
//    bool compare (StopTime i, StopTime j) { return (i.stop_sequence < j.stop_sequence); };
    typedef vector<StopTime*> StopTimeList;
    typedef StopTimeList::iterator iterator;
    typedef StopTimeList::const_iterator const_iterator;
    StopTime *beginTime;
    StopTime *endTime;

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
    void getBeginAndEndTime();
    string getBeginTime();
    string getEndTime();
};

#endif
