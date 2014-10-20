var express = require('express')
var app = express();
var pg = require('pg');
var Route = require('./lib/route.js');
var query = require('./lib/db.js');
var routes = {};

app.get('/db', function (request, response) {
//  pg.connect(process.env.DATABASE_URL, function(err, client, done) {
//    client.query('SELECT * FROM routes', function(err, result) {
//      done();
    console.log('DATABASEURL: '+process.env.DATABASE_URL);
    query.connectionParameters = process.env.DATABASE_URL;
    query('SELECT * from routes', function(err, rows, result) {
      if (err) {
          console.error(err); response.send("Error " + err);
      }
      else {
        var callback = function(id) {
          console.log('finished setting up route: '+id);
        }
        console.log('Result: %j',result);
        for (var i in result) {
          var row = result[i];
          routes[row.id] = new Route(row.id, row.short_name, row.long_name, row.type, callback); 
        }
        response.send('Completed');
      } 
    });
//  });
})

app.set('port', (process.env.PORT || 5000))
app.use(express.static(__dirname + '/public'))

app.get('/', function(request, response) {
  response.send('Hello World!')
})

app.listen(app.get('port'), function() {
  console.log("Node app is running at localhost:" + app.get('port'))
})
