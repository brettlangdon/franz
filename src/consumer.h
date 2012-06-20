#define BUILDING_NODE_EXTENSION
#ifndef CONSUMER_H
#define CONSUMER_H

#include <node.h>

class Consumer : public node::ObjectWrap {
 public:
  static void Init();
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);

 private:
  Consumer();
  ~Consumer();

  static v8::Persistent<v8::Function> constructor;
  static v8::Handle<v8::Value> New(const v8::Arguments& args);
};

#endif
