#include <node.h>

#include <pqxx/pqxx>
#include "interface.h"
#include "./lib/service.h"
#include "./lib/bus.h"

using namespace v8;

static Persistent<String> route_symbol;
static Persistent<String> tripId_symbol;
static Persistent<String> latitude_symbol;
static Persistent<String> longitude_symbol;

Persistent<Function> Interface::constructor;

Interface::Interface(String databaseUrl) : databaseUrl_(databaseUrl) {

}

Interface::~Interface() {

}

void Interface::Init(Handle<Object> exports) {
  route_symbol = NODE_PSYMBOL("route");
  tripId_symbol = NODE_PSYMBOL("tripId");
  latitude_symbol = NODE_PSYMBOL("latitude");
  longitude_symbol = NODE_PSYMBOL("longitude");

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Interface"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("beginService"),
      FunctionTemplate::New(BeginService)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("updateTrip"),
      FunctionTemplate::New(UpdateTrip)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("getBuses"),
      FunctionTemplate::New(GetBuses)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("updateBus"),
      FunctionTemplate::New(UpdateBus)->GetFunction());
  constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Interface"), constructor);
}

Handle<Value> Interface::New(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Number::New(1));
}

Handle<Value> Interface::BeginService(const Arguments& args) {
  HandleScope scope;
//  json::value returnObject;
//  returnObject[L"firstname"] = json::value::string(L"aaron");
//  returnObject[L"lastname"] = json::value::string(L"eisses");
//  return scope.Close(returnObject);
  Service::startService();
  return scope.Close(Number::New(2));
}

Handle<Value> Interface::UpdateTrip(const Arguments& args) {
  HandleScope scope;
  Service::updateTrips();
  return scope.Close(Number::New(3));
}

Handle<Value> Interface::GetBuses(const Arguments& args) {
  HandleScope scope;
  vector<Bus*> buses = Service::buses;
  v8::Local<v8::Array> busesArray = v8::Array::New(buses.size());

  for (unsigned int i=0; i<buses.size(); i++) {
    Bus* bus = buses[i];
    Local<Object> node_obj = Object::New();
    node_obj->Set(route_symbol, String::New(bus->route.c_str()));
    node_obj->Set(tripId_symbol, String::New(bus->tripId.c_str()));
    node_obj->Set(latitude_symbol, Number::New(bus->getLatitude()));
    node_obj->Set(longitude_symbol, Number::New(bus->getLongitude()));
    busesArray->Set(i, node_obj);
  }

  return scope.Close(busesArray);
}

Handle<Value> Interface::UpdateBus(const Arguments& args) {
  HandleScope scope; 
  return scope.Close(Number::New(4));
}

