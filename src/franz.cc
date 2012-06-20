#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "producer.h"
#include "consumer.h"

using namespace v8;

Handle<Value> CreateProducer(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Producer::NewInstance(args));
}

Handle<Value> CreateConsumer(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Consumer::NewInstance(args));
}

void InitAll(Handle<Object> target) {
  Producer::Init();
  Consumer::Init();

  target->Set(String::NewSymbol("createProducer"),
	      FunctionTemplate::New(CreateProducer)->GetFunction());

  target->Set(String::NewSymbol("createConsumer"),
	      FunctionTemplate::New(CreateConsumer)->GetFunction());
}

NODE_MODULE(franz, InitAll)
