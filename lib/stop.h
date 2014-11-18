#ifndef STOP_H
#define STOP_H

#include <string>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class Stop {
  private:
    bool operator== (const Stop& lhs) {
      if (this->id == lhs.id) {
        return true;
      }
      return false;
    }
    bool operator<= (const Stop& lhs) {
      if (this->id <= lhs.id) {
        return true;
      }
      return false;
    }
    bool operator>= (const Stop& lhs) {
      if (this->id >= lhs.id) {
        return true;
      }
      return false;
    }
    bool operator< (const Stop& lhs) {
      if (this->id < lhs.id) {
        return true;
      }
      return false;
    }
    bool operator> (const Stop& lhs) {
      if (this->id > lhs.id) {
        return true;
      }
      return false;
    }

  public:
    int id;
    string name;
    string stop_desc;
    double lat;
    double lng;
    string street;
    string city;
    string region;
    string postcode;
    string country;
    string zone_id;
    Stop(int);
    Stop(result::const_iterator);
    ~Stop();
};

#endif
