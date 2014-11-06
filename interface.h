#ifndef INTERFACE_H
#define INTERFACE_H 

#include <node.h>

class Interface : public node::ObjectWrap {
  public:
    static void Init(v8::Handle<v8::Object> exports);

  private:
    explicit Interface(const v8::String databaseUrl);
    ~Interface();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> BeginService(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetBuses(const v8::Arguments& args);
    static v8::Handle<v8::Value> UpdateBus(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    v8::String databaseUrl_;
};

#endif
