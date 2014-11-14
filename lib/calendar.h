#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <pqxx/pqxx>
#include <sstream>
#include "utils.h"

using namespace std;
using namespace pqxx;

class Calendar {

  private:
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int sunday;
    int start_date;
    int end_date;
    calendarDate getStartDate();
    calendarDate getEndDate();

  public:
    string id;
    Calendar(string, int, int, int, int, int, int, int, int, int);
    Calendar(result::const_iterator);
    ~Calendar();
    bool isValid();
};

#endif
