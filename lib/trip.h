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
#include "stops.h"
#include "paths.h"
#include "path.h"

class Route;

using namespace std;
using namespace pqxx;

class Trip {

  private:
    typedef vector<StopTime*> StopTimeList;
    StopTimeList stoptimes;
    StopTime *beginTime;
    StopTime *endTime;
    StopTime *nextStopTime;
    StopTime *currentStopTime;
    Calendar *calendar;
    Path *currentPath;
    PathElements::const_iterator nextStopPoint;
    PathElements::const_iterator currentStopPoint;
    typedef vector<CalendarDate*> CalendarDateList;
    CalendarDateList calendardates;
    void getCalendarForTrip();
    void getCalendarDatesForTrip();
    void loadStopTimes();
    void setNextStopTime(StopTimeList::const_iterator);
    void loadPath();
    bool sortBySequence(const StopTime&, const StopTime&);

  public:
    string routeId;
    string serviceId;
    string tripId;
    string tripHeadSign;
    int direction;
    string blockId;
    string shapeId;
    Trip(string, string, string, string, int, string, string);
    Trip(result::const_iterator);
    ~Trip();
    void getBeginAndEndTime();
    time_t getBeginTime();
    time_t getEndTime();
    void monitorTrip(Route*);
    bool isRunningToday();
    void alignToCurrentStopTime();
    void start();
    void end();
    Location* getCurrentLocationOnTrip(); 
    bool operator== (const Trip&);
};

#endif
