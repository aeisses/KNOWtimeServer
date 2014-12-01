#ifndef STOP_H
#define STOP_H

//#include <string>
#include <pqxx/pqxx>
#include "utils.h"

//using namespace std;
using namespace pqxx;

class Stop {
  private:
    Location *location;

  public:
    std::string id;
    std::string name;
    std::string stop_desc;
    std::string street;
    std::string city;
    std::string region;
    std::string postcode;
    std::string country;
    std::string zone_id;
    Stop(std::string);
    Stop(result::const_iterator);
    ~Stop();
    Location* getLocation();
//    bool operator==(const Stop&) const;
//    bool operator> (const Stop&);
//    bool operator< (const Stop&);
};

#endif
