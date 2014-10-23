var pg = require('pg');
var Bus = require('./bus.js');
var Path = require('./path.js');
var Stop = require('./stop.js');
var query = require('./query.js');
var Trip = require('./trip.js');

var _trips = {};
var _tripsLoaded = false;
var _stopsLoaded = false;
var _pathLoaded = false;

// Description:
//  Contructor for the Route class, this will create a route object
//  that will be responsible for determining when buses start and
//  stop on that route and holding onto the bus information.
// Returns:
//  The Route object
function Route(_id, _shortname, _longname, _type, _callback) {
  this.id = _id;
  this.shortname = _shortname;
  this.longname = _longname;
  this.type = _type;
  this.callback = _callback;
  this.buses = {};

  // Load the Paths and the Stops for the route from the database
  var funcCallback = function() {
 //   if (this.stopsLoaded && this.pathLoaded) {
    if (_tripsLoaded) {
      // Start the route
      _callback(_shortname);
    }
  };

  // Load the trips form the database
  query.connectionParameter = process.env.DATABASE_URL;
  query('SELECT * FROM trips WHERE route_id=$1',[this.id], function(err, rows, result) {
    if (err) {
      console.error(err);
    } else {
      for (var i in result.rows) {
        var row = result.rows[i];
        _trips[i] = new Trip(row.route_id, row.service_id, row.trip_id, row.trip_headsign, row.direction_id, row.block_id, row.shape_id);
      }
      _tripsLoaded = true;
      funcCallback();
    }
  });

  // Load the stops from the database
  this.stops = {};

  // Load the path from the database
  this.path = "";
}

// Below here needs some work.....
function loadStops() {

}

function loadPaths() {

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

// Description:
//  This will return the trips for this route
// Return:
//  An array for trips for this route
Route.prototype.getTrips = function() {
  return this.trips;
}

// Export the class
module.exports = Route;
