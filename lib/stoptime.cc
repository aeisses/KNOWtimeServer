#include "stoptime.h"

StopTime::StopTime () {
  trip_id = "";
  arrival_time = "";
  departure_time = "";
  stop_id = 0;
  stop_sequence = 0;
  pickup_type = 0;
  drop_off_type = 0;
}

StopTime::StopTime (string _trip_id, string _arrival_time, string _departure_time, int _stop_id, int _stop_sequence, int _pickup_type, int _drop_off_type) {
  trip_id = _trip_id;
  arrival_time = _arrival_time;
  departure_time = _departure_time;
  stop_id = _stop_id;
  stop_sequence = _stop_sequence;
  pickup_type = _pickup_type;
  drop_off_type = _drop_off_type;
}

StopTime::StopTime (result::const_iterator c) {
  
  // Get the trip_id if the value is not null
  if (c[0].is_null()) {
    trip_id = "";
  } else {
    trip_id = c[0].as<string>();
  }

  // Get the arrival_time if the value is not null
  if (c[1].is_null()) {
    arrival_time = "";
  } else {
    arrival_time = c[1].as<string>();
  }

  // Get the departure_time if the value is not null
  if (c[2].is_null()) {
    departure_time = "";
  } else {
    departure_time = c[2].as<string>();
  }

  // Get the stop_id if the value is not null
  if (c[3].is_null()) {
    stop_id = 0;
  } else {
    stop_id = c[3].as<int>();
  }

  // Get the stop_sequence if the value is not null
  if (c[4].is_null()) {
    stop_sequence = 0;
  } else {
    stop_sequence = c[4].as<int>();
  }

  // Get the pickup_type if the value is not null
  if (c[5].is_null()) {
    pickup_type = 0;
  } else {
    pickup_type = c[5].as<int>();
  }

  // Get the drop_off_type if the value is not null
  if (c[6].is_null()) {
    drop_off_type = 0;
  } else {
    drop_off_type = c[6].as<int>();
  }
}

StopTime::~StopTime () {

}
