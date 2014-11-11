#include "calendardate.h"

// CalendarDate Constructor
CalendarDate::CalendarDate(string _id, int _date, int _exception_type) {
  id = _id;
  date = _date;
  exception_type = _exception_type;
}

// CalendarDate Constructor
CalendarDate::CalendarDate(result::const_iterator c) {

  // Get the id if the value is not null
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }
  
  // Get the date if the value is not null
  if (c[1].is_null()) {
    date = 0;
  } else {
    date = c[1].as<int>();
  }
  
  // Get the exception_type if the value is not null
  if (c[2].is_null()) {
    exception_type = 0;
  } else {
    exception_type = c[2].as<int>();
  }
}

// CalendarDate Destructor
CalendarDate::~CalendarDate() {

}
