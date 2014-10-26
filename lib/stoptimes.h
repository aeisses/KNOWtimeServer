#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>

using namespace std;

class StopTimes {
  public:
    string trip_id;
    string arrival_time;
    string departure_time;
    int stop_id;
    int stop_sequence;
    int pickup_type;
    int drop_off_type;
    StopTimes(string, string, string, int, int, int, int);
};

#endif
