#include "stoptimes.h"

StopTimes::StopTimes(string _trip_id, string _arrival_time, string _departure_time, int _stop_id, int _stop_sequence, int _pickup_type, int _drop_off_type) {
  trip_id = _trip_id;
  arrival_time = _arrival_time;
  departure_time = _departure_time;
  stop_id = _stop_id;
  stop_sequence = _stop_sequence;
  pickup_type = _pickup_type;
  drop_off_type = _drop_off_type;
}
