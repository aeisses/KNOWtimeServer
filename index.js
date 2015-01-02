var WebSocketServer = require("ws").Server
var http = require("http")
var express = require('express')
var app = express()
var port = process.env.PORT || 5000

app.use(express.static(__dirname + "/"))

var server = http.createServer(app)
server.listen(port)

console.log("http server listening on %d", port)

//var pg = require('pg')

var addon = require('./build/Release/addon')
var obj = new addon.Interface("junk")
console.log( obj.beginService() );

var wss = new WebSocketServer({server: server})
console.log("websocket server created")

wss.on("connection", function(ws) {
  var id = setInterval(function() {
    obj.updateTrip();
//    ws.send(JSON.stringify(new Date()), function() { })function
    console.log(obj.getBuses())
    var busArray = obj.getBuses()
    for (var i = 0; i < busArray.length; i++) {
      var json = busArray[i];
      ws.send(JSON.stringify(json), function() { })
    }
  }, 10000)

  console.log("websocket connection open")

  ws.on("message", function(data) {
    var json = JSON.parse(data)
    console.log("Action: "+json.action)
    switch(json.action) {
      case "GET":
        console.log("Made it to Get");
        switch(json.type) {
          case "kGetRouteByRouteId":
            console.log("Made it to GetRouteByRouteId");
            console.log(obj.getBuses())
            ws.send(obj.getBuses())
            break;
        }
        break;
      default:
    }
  });

  ws.on("close", function() {
    console.log("websocket connection close")
    clearInterval(id)
  });
});

//app.set('port', port)
//app.use(express.static(__dirname + '/public'))

//app.get('/', function(request, response) {
//  response.send('Hello World!')
//})

//app.listen(app.get('port'), function() {
//  console.log("Node app is running at localhost:" + app.get('port'))
//  console.log("Loading Service");
//  console.log( obj.beginService() );
//  console.log( obj.getBuses() );
//})
