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
