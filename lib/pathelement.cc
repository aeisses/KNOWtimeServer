#include "path.h"

PathElement::PathElement(double _lat, double _lng) {
  location = new Location();
  location->latitude = _lat;
  location->longitude = _lng;
  sequence = 0;
}

PathElement::PathElement(result::const_iterator c) {
  // Create a new location
  location = new Location();

  // Get the lat if the value is not NULL
  if (c[1].is_null()) {
    location->latitude = -1;
  } else {
    location->latitude = c[1].as<double>();
  }
  
  // Get the lng if the value is not NULL
  if (c[2].is_null()) {
    location->longitude = -1;
  } else {
    location->longitude = c[2].as<double>();
  }

  // Get the squence if the value is not NULL
  if (c[3].is_null()) {
    sequence = 0;
  } else {
    sequence = c[3].as<int>();
  }
}

PathElement::~PathElement() {
  delete location;
}

Location* PathElement::getLocation() {
  return location;
}

bool PathElement::operator== (const PathElement& lhs) {
  if (this->sequence == lhs.sequence) {
    return true;
  }
  return false;
}

bool PathElement::operator> (const PathElement& lhs) {
  if (this->sequence > lhs.sequence) {
    return true;
  }
  return false;
}

bool PathElement::operator< (const PathElement& lhs) {
  if (this->sequence < lhs.sequence) {
    return true;
  }
  return false;
}

