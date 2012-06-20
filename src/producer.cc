#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "producer.h"

using namespace v8;

Producer::Producer() {};
Producer::~Producer() {};

Persistent<Function> Producer::constructor;

void Producer::Init() {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Producer"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);


  constructor = Persistent<Function>::New(tpl->GetFunction());
}

Handle<Value> Producer::New(const Arguments& args) {
  HandleScope scope;

  Producer* obj = new Producer();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> Producer::NewInstance(const Arguments& args) {
  HandleScope scope;

  const unsigned argc = 0;
  Handle<Value> argv[argc] = {};
  Local<Object> instance = constructor->NewInstance(argc, argv);

  return scope.Close(instance);
}
