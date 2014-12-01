#ifndef STOPTIME_H
#define STOPTIME_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"
#include "utils.h"

using namespace std;
using namespace pqxx;

class StopTime {
    
  private:
    string trip_id;
    int pickup_type;
    int drop_off_type;
    string arrival_time;
    string departure_time;

  public:
    string stopId;
    int stop_sequence;
    StopTime();
    StopTime(string, string, string, string, int, int, int);
    StopTime(result::const_iterator);
    ~StopTime();
    time_t getArrivalTime();
    time_t getDepartureTime();
    bool operator== (const StopTime&);
    bool operator<= (const StopTime&);
    bool operator>= (const StopTime&);
    bool operator> (const StopTime&);
    bool operator< (const StopTime&);
};

#endif
