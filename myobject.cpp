// myobject.cc
#include "myobject.h"

#include "Gpio.h"
using namespace v8;

Persistent<Function> MyObject::constructor;

MyObject::MyObject(double value) : value_(value), leftPort(27,Gpio::out),rightPort(22,Gpio::out){


std::cout  << "KONSTRUKTOR" << std::endl;
this->leftPort.open();
this->rightPort.open();

}

MyObject::~MyObject() {



}

void MyObject::Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "MyObject"));
  tpl->InstanceTemplate()->SetInternalFieldCount(3);

  // Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);
	NODE_SET_PROTOTYPE_METHOD(tpl,"close",close);	
	NODE_SET_PROTOTYPE_METHOD(tpl,"left",left);
	NODE_SET_PROTOTYPE_METHOD(tpl,"right",right);
	NODE_SET_PROTOTYPE_METHOD(tpl,"stop",stop);
	NODE_SET_PROTOTYPE_METHOD(tpl,"forward",forward);
	NODE_SET_PROTOTYPE_METHOD(tpl,"open",open);
  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "MyObject"),
               tpl->GetFunction());
}

void MyObject::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    MyObject* obj = new MyObject(value);
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `MyObject(...)`, turn into construct call.
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    args.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void MyObject::PlusOne(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);




  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.Holder());
  obj->value_ += 1;

  args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}
void MyObject::close(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate=Isolate::GetCurrent();
	HandleScope scope(isolate);
	
	MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.Holder());	

	if(obj->leftPort.close() && obj->rightPort.close())
	{
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "OK"));
	}
	else
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "ERROR - OPENING"));
}
void MyObject::open(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate=Isolate::GetCurrent();
	HandleScope scope(isolate);

	MyObject *obj=ObjectWrap::Unwrap<MyObject>(args.Holder());
	obj->leftPort.open();
	obj->rightPort.open();
}
void MyObject::left(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate=Isolate::GetCurrent();
	HandleScope scope(isolate);

	MyObject *obj=ObjectWrap::Unwrap<MyObject>(args.Holder());

	
	obj->leftPort.setValue(0);
	obj->rightPort.setValue(1);
	
}
void MyObject::right(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate=Isolate::GetCurrent();
	HandleScope scope(isolate);

	MyObject *obj=ObjectWrap::Unwrap<MyObject>(args.Holder());
	obj->leftPort.setValue(1);
	obj->rightPort.setValue(0);
	
}

void MyObject::stop(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate=Isolate::GetCurrent();
	HandleScope scope(isolate);

	MyObject *obj=ObjectWrap::Unwrap<MyObject>(args.Holder());

	obj->leftPort.setValue(0);
	obj->rightPort.setValue(0);
}

void MyObject::forward(const FunctionCallbackInfo<Value>& args)
{
        Isolate* isolate=Isolate::GetCurrent();
        HandleScope scope(isolate);

        MyObject *obj=ObjectWrap::Unwrap<MyObject>(args.Holder());

        obj->leftPort.setValue(1);
        obj->rightPort.setValue(1);
}


