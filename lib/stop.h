#ifndef STOP_H
#define STOP_H

#include <string>

using namespace std;

class Stop {
  private:
    string street;
    string city;
    string region;
    string postcode;
    string country;
    string zone_id;

  public:
    int id;
    string name;
    string stop_desc;
    double lat;
    double lng;
    Stop(int, string, string, double, double, string, string, string, string, string, string);
};

#endif
