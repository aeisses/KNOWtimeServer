var express = require('express')
var app = express();
var pg = require('pg');

var addon = require('./build/Release/addon');
var obj = new addon.Interface("junk");

app.set('port', (process.env.PORT || 5000))
app.use(express.static(__dirname + '/public'))

app.get('/', function(request, response) {
  response.send('Hello World!')
})

app.listen(app.get('port'), function() {
  console.log("Node app is running at localhost:" + app.get('port'))
  console.log("Loading Service");
  console.log( obj.beginService() );
  console.log( obj.getBuses() );
})
