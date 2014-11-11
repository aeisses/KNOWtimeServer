#ifndef CALENDARDATE_H
#define CALENDARDATE_H

#include <string>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class CalendarDate {
  public:
    string id;
    int date;
    int exception_type;
    CalendarDate(string, int, int);
    CalendarDate(result::const_iterator);
    ~CalendarDate();
};

#endif
