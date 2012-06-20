#define BUILDING_NODE_EXTENSION
#ifndef PRODUCER_H
#define PRODUCER_H

#include <node.h>

class Producer : public node::ObjectWrap {
 public:
  static void Init();
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);

 private:
  Producer();
  ~Producer();

  static v8::Persistent<v8::Function> constructor;
  static v8::Handle<v8::Value> New(const v8::Arguments& args);
};

#endif
