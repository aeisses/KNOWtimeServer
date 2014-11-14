#include "calendar.h"

Calendar::Calendar(string _id, int _monday, int _tuesday, int _wednesday, int _thursday, int _friday, int _saturday, int _sunday, int _start_date, int _end_date) {
  id = _id;
  monday = _monday;
  tuesday = _tuesday;
  wednesday = _wednesday;
  thursday = _thursday;
  friday = _friday;
  saturday = _saturday;
  sunday = _sunday;
  start_date = _start_date;
  end_date = _end_date;
}

Calendar::Calendar(result::const_iterator c) {

  // Get the id if the value is not null
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }

  // Get the monday value if the value is not null
  if (c[1].is_null()) {
    monday = 0;
  } else {
    monday = c[1].as<int>();
  }

  // Get the tueday value if the value is not null
  if (c[2].is_null()) {
    tuesday = 0;
  } else {
    tuesday = c[2].as<int>();
  }

  // Get the wednesday value if the value is not null
  if (c[3].is_null()) {
    wednesday = 0;
  } else {
    wednesday = c[3].as<int>();
  }

  // Get the thursday value if the value is not null
  if (c[4].is_null()) {
    thursday = 0;
  } else {
    thursday = c[4].as<int>();
  }

  // Get the friday value if the value is not null
  if (c[5].is_null()) {
    friday = 0;
  } else {
    friday = c[5].as<int>();
  }

  // Get the saturday value if the value is not null
  if (c[6].is_null()) {
    saturday = 0;
  } else {
    saturday = c[6].as<int>();
  }

  // Get the sunday value if the value is not null
  if (c[7].is_null()) {
    sunday = 0;
  } else {
    sunday = c[7].as<int>();
  }

  // Get the start_date value if the value is not null
  if (c[8].is_null()) {
    start_date = 0;
  } else {
    start_date = c[8].as<int>();
  }

  // Get the end_date value if the value is not null
  if (c[9].is_null()) {
    end_date = 0;
  } else {
    end_date = c[9].as<int>();
  }
}

Calendar::~Calendar() {

}

calendarDate Calendar::getStartDate() {
  ostringstream convert;
  convert << start_date;
  return Utils::getCalendarDate(convert.str());
}

calendarDate Calendar::getEndDate() {
  ostringstream convert;
  convert << end_date;
  return Utils::getCalendarDate(convert.str());
}

bool Calendar::isValid() {
  time_t currentTime = Utils::getLocalTime();

  tm *ltm = localtime(&currentTime);

  // Check the if the day of the week is valida
  switch (ltm->tm_wday) {
    case 0:
      if (sunday != 1) return false; 
      break;
    case 1:
      if (monday != 1) return false;
      break;
    case 2:
      if (tuesday != 1) return false;
      break;
    case 3:
      if (wednesday != 1) return false;
      break;
    case 4:
      if (thursday != 1) return false;
      break;
    case 5:
      if (friday != 1) return false;
      break;
    case 6:
      if (saturday != 1) return false;
      break;
  }

  // Check the time is in between the start_time and end_time
  calendarDate startDate = getStartDate();
  calendarDate endDate = getEndDate();

  // Confirm the startDate is before the currentDate
  if (!(startDate.year < ltm->tm_year+1900 || (startDate.year == ltm->tm_year+1900 && (startDate.month < ltm->tm_mon+1 || (startDate.month == ltm->tm_mon+1 && startDate.day <= ltm->tm_mday))))) {
    return false;
  }

  if (!(endDate.year > ltm->tm_year+1900 || (endDate.year == ltm->tm_year+1900 && (endDate.month > ltm->tm_mon+1 || (endDate.month == ltm->tm_mon+1 && endDate.day >= ltm->tm_mday))))) {
    return false;
  }

  return true;
}
