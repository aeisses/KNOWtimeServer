#include "trip.h"

Trip::Trip(string _routeId, string _serviceId, string _tripId, string _tripHeadSign, string _directionId, string _blockId, string _shapeId) {
  routeId = _routeId;
  serviceId = _serviceId;
  tripId = _tripId;
  tripHeadSign = _tripHeadSign;
  directionId = _directionId;
  blockId = _blockId;
  shapeId = _shapeId;
}

