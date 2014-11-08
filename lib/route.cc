#include <route.h>

Route::Route (result::const_iterator c) {

  // Get the id if the value is not null
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }

  // Get the shortName if the value is not null
  if (c[1].is_null()) {
    shortName = "";
  } else {
    shortName = c[1].as<string>();
  }

  // Get the longName if the value is not null
  if (c[2].is_null()) {
    longName = "";
  } else {
    longName = c[2].as<string>();
  }

  // Get the desc if the value is not null
  if (c[3].is_null()) {
    desc = "";
  } else {
    desc = c[3].as<string>();
  }

  // Get the type if the value is not null
  if (c[4].is_null()) {
    type = 0;
  } else {
    type = c[4].as<int>();
  }
}

Route::Route (string _id, string _shortName, string _longName, string _desc, int _type) {
  id = _id;
  shortName = _shortName;
  longName = _longName;
  desc = _desc;
  type = _type;
}

// Destructor
Route::~Route() {

}
