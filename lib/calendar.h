#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <pqxx/pqxx>

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

  public:
    string id;
    int start_date;
    int end_date;
    Calendar(string, int, int, int, int, int, int, int, int, int);
    Calendar(result::const_iterator);
    ~Calendar();
    bool isMonday();
    bool isTuesday();
    bool isWednesday();
    bool isThursday();
    bool isFriday();
    bool isSaturday();
    bool isSunday();
};

#endif
