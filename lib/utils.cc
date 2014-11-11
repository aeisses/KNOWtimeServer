#include "utils.h"

// To figure out what is going on here make sure you reference:
// http://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

// Take a string in the structure of HH:MM:SS, add that to today
// and return the number of seconds since January 1, 1970
time_t Utils::getDateFromTime(string hoursMinutesSeconds) {
  // Get the current time
  time_t now = time(0);

  // Get the local time
  tm *ltm = localtime(&now);

  // Get the hours, minutes, and seconds from the input string
  int counter = 0;
  string delimiter = ":";
  size_t pos = 0;
  string token;
  while ((pos = hoursMinutesSeconds.find(delimiter)) != string::npos) {
    token = hoursMinutesSeconds.substr(0, pos);
    stringstream str(token);
    if (counter == 0) {
      int hours = 0;
      str >> hours;
      // We need to do a little check here, if the hours is early in the morning,
      // before 3:00 am we need to move the time to the next day
      if (hours < 3) {
        ltm->tm_mday += 1; 
      }
      ltm->tm_hour = hours;
    } else if (counter == 1) {
      str >> ltm->tm_min;
    } else if (counter == 2) {
      str >> ltm->tm_sec;
    }
    counter++;
    hoursMinutesSeconds.erase(0, pos + delimiter.length());
  }

  // Return the time object
  return mktime( ltm );
}
