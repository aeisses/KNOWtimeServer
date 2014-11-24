#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct calendarDate {
  int year;
  int month;
  int day;
};

struct Location {
  double latitude;
  double longitude;
};

class Utils {

  private:

  public:
    static calendarDate getCalendarDate(string);
    static time_t getLocalTime();
    static time_t getDateFromTime(string);
};

#endif
