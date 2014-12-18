#include "bus.h"

// Private Methods


// Public Methods
Bus::Bus(string _tripId, string _route, Location *_location) {
  tripId = _tripId;
  route = _route;
  location = new Location();
  location->latitude = _location->latitude;
  location->longitude = _location->longitude;
}

Bus::~Bus() {
  delete location;
}

void Bus::updateLocation(Location *_location) {
  if (_location->latitude != 0 && _location->longitude != 0) {
    location->latitude = _location->latitude;
    loacation->longitude = _location->longitude;
  }
}

