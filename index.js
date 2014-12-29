var express = require('express')
var app = express()
var pg = require('pg')

var addon = require('./build/Release/addon')
var obj = new addon.Interface("junk")

var http = require("http")
var WebSocketServer = require("ws").Server

var port = process.env.PORT || 5000

var server = http.createServer(app)
server.listen(6000)

console.log("http server listening on %d", 6000)

var wss = new WebSocketServer({server: server})
console.log("websocket server created")

wss.on("connection", function(ws) {
  var id = setInterval(function() {
    ws.send(JSON.stringify(new Date()), function() { })
  }, 1000)

  console.log("websocket connection open")

  ws.on("close", function() {
    console.log("websocket connection close")
    clearInterval(id)
  });
});

app.set('port', port)
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
