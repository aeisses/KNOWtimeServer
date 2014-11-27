#include "stop.h"

Stop::Stop(string _id) {
  id = _id;
  name = "";
  stop_desc = "";
  location = new Location();
  location->latitude = -1;
  location->longitude = -1;
  street = "";
  city = "";
  region = "";
  postcode = "";
  country = "";
  zone_id = "";
}

Stop::Stop(result::const_iterator c) {

  // Get the id if the value is not NULL
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }

  // Get the name if the value is not NULL
  if (c[1].is_null()) {
    name = "";
  } else {
    name = c[1].as<string>();
  }

  // Get the stop_desc if the value is not NULL
  if (c[2].is_null()) {
    stop_desc = "";
  } else {
    stop_desc = c[2].as<string>();
  }

  location = new Location();

  // Get the lat if the value is not NULL
  if (c[3].is_null()) {
    location->latitude = -1;
  } else {
    location->latitude = c[3].as<double>();
  }

  // Get the lng if the value is not NULL
  if (c[4].is_null()) {
    location->longitude = -1;
  } else {
    location->longitude = c[4].as<double>();
  }

  // Get the street if the value is not NULL
  if (c[5].is_null()) {
    street = "";
  } else {
    street = c[5].as<string>();
  }

  // Get the city if the value is not NULL
  if (c[6].is_null()) {
    city = "";
  } else {
    city = c[6].as<string>();
  }

  // Get the region if the value is not NULL
  if (c[7].is_null()) {
    region = "";
  } else {
    region = c[7].as<string>();
  }

  // Get the postcode if the value is not NULL
  if (c[8].is_null()) {
    postcode = "";
  } else {
    postcode = c[8].as<string>();
  }

  // Get the country if the value is not NULL
  if (c[9].is_null()) {
    country = "";
  } else {
    country = c[9].as<string>();
  }

  // Get the zone_id if the value is not NULL
  if (c[10].is_null()) {
    zone_id = "";
  } else {
    zone_id = c[10].as<string>();
  }
}

Stop::~Stop() {
  delete location;
}

Location* Stop::getLocation() {
  return location;
}

