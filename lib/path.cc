#include "path.h"

Path::Path(string _id) {
  id = _id;
  lat = 0.0;
  lng = 0.0;
  sequence = 0;
}

Path::Path(result::const_iterator c) {
  
  // Get the id if the value is not NULL
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }

  // Get the lat if the value is not NULL
  if (c[1].is_null()) {
    lat = 0.0;
  } else {
    lat = c[1].as<double>();
  }
  
  // Get the lng if the value is not NULL
  if (c[2].is_null()) {
    lng = 0.0;
  } else {
    lng = c[2].as<double>();
  }

  // Get the squence if the value is not NULL
  if (c[3].is_null()) {
    sequence = 0;
  } else {
    sequence = c[3].as<int>();
  }

}

Path::~Path() {

}
