#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>

using namespace std;

class CalendarDates {
  public:
    string id;
    int date;
    int exception_type;
    CalendarDates(string, int, int);
};

#endif
