#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <algorithm>
#include <vector>
#include <pqxx/pqxx>
#include "database.h"
#include "stoptime.h"
#include "calendar.h"
#include "calendardate.h"

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
// Uncomment when needed
//    typedef StopTimeList::iterator st_terator;
//    typedef StopTimeList::const_iterator st_const_iterator;
    StopTime *beginTime;
    StopTime *endTime;
    Calendar *calendar;
    typedef vector<CalendarDate*> CalendarDateList;
    CalendarDateList calendardates;
// Uncomment when needed
//    typedef CalendarDateList::iterator cd_iterator;
//    typedef CalendarDateList::const_iterator cd_const_iterator;
    void getCalendarForTrip();
    void getCalendarDatesForTrip();

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
