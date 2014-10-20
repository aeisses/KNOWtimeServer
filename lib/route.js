var pg = require('pg');
var Bus = require('./bus.js');
var Path = require('./path.js');
var Stop = require('./stop.js');
var query = require('./db.js');
var Trip = require('./trip.js');

var trips = {};

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
  this.stopsLoaded = false;
  this.pathLoaded = false;
  this.tripsLoaded = false;

  console.log('Route Callback: '+callback);
  // Load the Paths and the Stops for the route from the database
  var funcCallback = function() {
 //   if (this.stopsLoaded && this.pathLoaded) {
    if (this.trip) {
      // Start the route
      this.callback(this.id);
    }
  };

  // Load the trips for the database
  query.connectionParameter = process.env.DATABASE_URL;
  query('SELECT * FROM trips WHERE route_id=$1',[this.id], function(err, rows, result) {
    if (err) {
      console.error(err);
    } else {
      console.log('Trips: %j',result);
      for (var i in result) {
        var row = result[i];
        trips[i] = new Trip(row.route_id, row.service_id, row.trip_id, row.trip_headsign, row.direction_id, row.block_id, row.shape_id);
      }
      this.trip = true;
//      funcCallback();
    }
  });
//  pg.connect(process.env.DATABASE_URL, function(err, client, done) {
//    console.log("RouteId: "+this.id);
//    client.query('SELECT * FROM trips WHERE route_id=\''+this.id+'\'', function(err, result) {
//     if (err) {
//        console.error(err);
//      } else {
//        for (var i in result.row) {
//          var row = result.row[i];
//          trips[i] = new Trip(row.route_id, row.service_id, row.trip_id, row.trip_headsign, row.direction_id, row.block_id, row.shape_id);
//        }
//        this.trip = true;
//        funcCallback();
//      }
//    });
//  });

  // Load the stops from the database
  this.stops = {};

  // Load the path from the database
  this.path = "";
}

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
