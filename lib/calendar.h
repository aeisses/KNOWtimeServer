#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>

using namespace std;

class Calendar {
  public:
    string id;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int sunday;
    int start_date;
    int end_date;
    Calendar(string, int, int, int, int, int, int, int, int, int);
};

#endif
