var express = require('express')
var app = express();
var pg = require('pg');
var Route = require('./lib/route.js');
var query = require('./lib/query.js');
var routes = {};

var addon = require('./build/Release/addon');
console.log(addon);
var obj = new addon.Interface("junk");
console.log(obj);
console.log( obj.beginService() );
console.log( obj.getBuses() );
console.log( obj.updateBus() );

app.get('/db', function (request, response) {
    query.connectionParameters = process.env.DATABASE_URL;
    query('SELECT * from routes', function(err, rows, result) {
      if (err) {
          console.error('Error with a databse query: '+err); 
      }
      else {
        var callback = function(id) {
          console.log('finished setting up route: '+id);
        }
        for (var i in result.rows) {
          var row = result.rows[i];
          routes[row.id] = new Route(row.id, row.short_name, row.long_name, row.type, callback); 
        }
        response.send('Completed');
      } 
    });
})

app.set('port', (process.env.PORT || 5000))
app.use(express.static(__dirname + '/public'))

app.get('/', function(request, response) {
  response.send('Hello World!')
})

app.listen(app.get('port'), function() {
  console.log("Node app is running at localhost:" + app.get('port'))
})
