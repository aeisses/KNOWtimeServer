#include <node.h>
#include "interface.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  Interface::Init(exports);
}

NODE_MODULE(addon, InitAll);

