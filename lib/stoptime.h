#ifndef STOPTIME_H
#define STOPTIME_H

#include <string>
#include <pqxx/pqxx>
#include "database.h"

using namespace std;
using namespace pqxx;

class StopTime {
    
  private:
    string trip_id;
    int stop_sequence;
    int pickup_type;
    int drop_off_type;
    bool operator== (const StopTime& lhs) {
      if (this->stop_sequence == lhs.stop_sequence) {
        return true;
      }
      return false;
    }
    bool operator<= (const StopTime& lhs) {
      if (this->stop_sequence <= lhs.stop_sequence) {
        return true;
      }
      return false;
    }
    bool operator>= (const StopTime& lhs) {
      if (this->stop_sequence >= lhs.stop_sequence) {
        return true;
      }
      return false;
    }
    bool operator> (const StopTime& lhs) {
      if (this->stop_sequence > lhs.stop_sequence) {
        return true;
      }
      return false;
    }
    bool operator< (const StopTime& lhs) {
      if (this->stop_sequence < lhs.stop_sequence) {
        return true;
      }
      return false;
    }

  public:
    int stop_id;
    string arrival_time;
    string departure_time;
    StopTime();
    StopTime(string, string, string, int, int, int, int);
    StopTime(result::const_iterator);
    ~StopTime();
    void getArivalTime();
    void getDepartureTime();
};

#endif
