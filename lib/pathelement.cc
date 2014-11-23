#include "path.h"

PathElement::PathElement(double _lat, double _lng) {
  lat = _lat;
  lng = _lng;
  sequence = 0;
}

PathElement::PathElement(result::const_iterator c) {
  
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

PathElement::~PathElement() {

}
