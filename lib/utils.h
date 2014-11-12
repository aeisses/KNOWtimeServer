#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Utils {

  private:

  public:
    static time_t getLocalTime();
    static time_t getDateFromTime(string);
};

#endif
