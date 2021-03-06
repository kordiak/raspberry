// myobject.h
#ifndef MYOBJECT_H
#define MYOBJECT_H
#include "Gpio.h"
#include <node.h>
#include <node_object_wrap.h>

class MyObject : public node::ObjectWrap {
 public:
static void Init(v8::Handle<v8::Object> exports);

 private:
  explicit MyObject(double value = 0);
  ~MyObject();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args);
 static void close(const v8::FunctionCallbackInfo<v8::Value>& args);
static void open(const v8::FunctionCallbackInfo<v8::Value>& args);
static void left(const v8::FunctionCallbackInfo<v8::Value>& args);
static void right(const v8::FunctionCallbackInfo<v8::Value>& args);
static void stop(const v8::FunctionCallbackInfo<v8::Value>& args); 
static void forward(const v8::FunctionCallbackInfo<v8::Value>& args);
static v8::Persistent<v8::Function> constructor;
  double value_;
	Gpio leftPort;
	Gpio rightPort;
};

#endif
