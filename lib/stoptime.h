#ifndef STOPTIME_H
#define STOPTIME_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"

using namespace std;
using namespace pqxx;

class StopTime {
  public:
    string trip_id;
    string arrival_time;
    string departure_time;
    int stop_id;
    int stop_sequence;
    int pickup_type;
    int drop_off_type;
    StopTime();
    StopTime(string, string, string, int, int, int, int);
    StopTime(result::const_iterator);
    ~StopTime();
};

#endif
