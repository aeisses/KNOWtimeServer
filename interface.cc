#include <node.h>
//#include <json.h>
#include "interface.h"
#include "./lib/route.h"

using namespace v8;

Persistent<Function> Interface::constructor;

Interface::Interface(String databaseUrl) : databaseUrl_(databaseUrl) {

}

Interface::~Interface() {

}

void Interface::Init(Handle<Object> exports) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Interface"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("beginService"),
      FunctionTemplate::New(BeginService)->GetFunction());
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
  return scope.Close(Number::New(2));
}

Handle<Value> Interface::GetBuses(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Number::New(3));
}

Handle<Value> Interface::UpdateBus(const Arguments& args) {
  HandleScope scope; 
  return scope.Close(Number::New(4));
}

