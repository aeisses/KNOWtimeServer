#ifndef STOP_H
#define STOP_H

#include <string>
#include <pqxx/pqxx>
#include "utils.h"

using namespace std;
using namespace pqxx;

class Stop {
  private:
    Location *location;
    bool operator== (const Stop& lhs) {
      if (this->id.compare(lhs.id) == 0) {
        return true;
      }
      return false;
    }
    bool operator> (const Stop& lhs) {
      if (this->id.compare(lhs.id) > 0) {
        return true;
      }
      return false;
    }
    bool operator< (const Stop& lhs) {
      if (this->id.compare(lhs.id) < 0) {
        return true;
      }
      return false;
    }

  public:
    string id;
    string name;
    string stop_desc;
    string street;
    string city;
    string region;
    string postcode;
    string country;
    string zone_id;
    Stop(string);
    Stop(result::const_iterator);
    ~Stop();
    Location* getLocation();
};

#endif
