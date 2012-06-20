#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "consumer.h"

using namespace v8;

Consumer::Consumer() {};
Consumer::~Consumer() {};

Persistent<Function> Consumer::constructor;

void Consumer::Init() {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Consumer"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);


  constructor = Persistent<Function>::New(tpl->GetFunction());
}

Handle<Value> Consumer::New(const Arguments& args) {
  HandleScope scope;

  Consumer* obj = new Consumer();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> Consumer::NewInstance(const Arguments& args) {
  HandleScope scope;

  const unsigned argc = 0;
  Handle<Value> argv[argc] = {};
  Local<Object> instance = constructor->NewInstance(argc, argv);

  return scope.Close(instance);
}
