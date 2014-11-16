#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <algorithm>
#include <vector>
#include <pqxx/pqxx>
#include <ctime>
#include "database.h"
#include "stoptime.h"
#include "calendar.h"
#include "calendardate.h"
#include "utils.h"

class Route;

using namespace std;
using namespace pqxx;

class Trip {

  private:
    typedef vector<StopTime*> StopTimeList;
    StopTimeList stoptimes;
//    typedef StopTimeList::iterator st_iterator;
//    typedef StopTimeList::const_iterator st_const_iterator;
    StopTime *beginTime;
    StopTime *endTime;
    StopTime *nextStopTime;
    StopTime *currentStopTime;
    Calendar *calendar;
    typedef vector<CalendarDate*> CalendarDateList;
    CalendarDateList calendardates;
// Uncomment when needed
//    typedef CalendarDateList::iterator cd_iterator;
//    typedef CalendarDateList::const_iterator cd_const_iterator;
    void getCalendarForTrip();
    void getCalendarDatesForTrip();
    void loadStopTimes();
    bool operator== (const Trip& lhs) {
      if (lhs.tripId == this->tripId) {
        return true;
      }
      return false;
    }

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
    time_t getBeginTime();
    time_t getEndTime();
    void monitorTrip(Route*);
    bool isRunningToday();
    void watchNextTrip();
    void checkMonitoredTrips();
    void alignToCurrentStopTime();
    void start();
};

#endif
