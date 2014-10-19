var Bus = require('./bus.js');
var Path = require('./path.js');
var Stop = require('./stop.js');

// Description:
//  Contructor for the Route class, this will create a route object
//  that will be responsible for determining when buses start and
//  stop on that route and holding onto the bus information.
// Returns:
//  The Route object
function Route(id, shortname, longname, type, callback) {
  this.id = id;
  this.shortname = shortname;
  this.longname = longname;
  this.type = type;
  this.callback = callback;
  this.buses = {};

  // Load the Paths and the Stops for the route from the database
  this.stops = {};
  this.path = "";

  // Start the route
//  console.log("Created route: "+shortname);
  this.callback(this.id);
}

// Description:
//  Returns the time the next bus will start on this route
//  This will only return the next bus on the given bus day,
//  The given bus day will run from say 2:00 am to 2:00 am.
// Return:
//  A time stamp of when the next bus will begin it trip.
Route.prototype.calculateNextBusStartTime = function() {

}

// Description:
//  This will return all the active buses currently on this route
// Return:
//  An array of buses that are currently active in on the route
Route.prototype.getBuses = function() {
  return this.buses;
}

// Description:
//  This will return the Path for this route
// Return:
//  A path object
Route.prototype.getPath = function() {
  return this.path;
}

// Description:
//  This will return the stops for this route
// Return:
//  An array of stops for this route
Route.prototype.getStops = function() {
  return this.stops;
}

// Export the class
module.exports = Route;
