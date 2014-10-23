// Description:
//  The constructor for the Trip object
// Returns:
//  The Trip object
function Trip(_routeId, _serviceId, _tripId, _tripHeadsign, _directionId, _blockId, _shapeId) {
  this.routeId = _routeId;
  this.serviceId = _serviceId;
  this.tripId = _tripId;
  this.tripHeadsign = _tripHeadsign;
  this.directionId = _directionId;
  this.blockId = _blockId;
  this.shapeId = _shapeId;
}

// Description:
//  The getter for the routeId
// Returns:
//  The routeId
Trip.prototype.getRouteId = function() {
  return this.routeId;
}

// Description:
//  The getter for the serviceId
// Returns:
//  The serviceId
Trip.prototype.getServiceId = function() {
  return this.serviceId;
}

// Description:
//  The getter for the tripId
// Returns:
//  The tripId
Trip.prototype.getTripId = function() {
  return this.tripId;
}

// Description:
//  The getter for the tripHeadsign
// Return:
//  The tripHeadsign
Trip.prototype.getTripHeadsign = function() {
  return this.tripHeadsign;
}

// Description:
//  The getter for the directionId
// Returns:
//  The directionId
Trip.prototype.getDirectionId = function() {
  return this.directionId;
}

// Description:
//  The getter for the blockId
// Returns:
//  The blockId
Trip.prototype.getBlockId = function() {
  return this.blockId;
}

// Description:
//  The getter for the shapeId
// Returns:
//  The shapeId
Trip.prototype.getShapeId = function() {
  return this.shapeId;
}
// Export the class
module.exports = Trip;
