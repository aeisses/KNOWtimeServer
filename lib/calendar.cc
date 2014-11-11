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

bool Calendar::isMonday() {
  if (monday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isTuesday() {
  if (tuesday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isWednesday() {
  if (wednesday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isThursday() {
  if (thursday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isFriday() {
  if (friday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isSaturday() {
  if (saturday == 1) {
    return true;
  }
  return false;
}

bool Calendar::isSunday() {
  if (sunday == 1) {
    return true;
  }
  return false;
}
