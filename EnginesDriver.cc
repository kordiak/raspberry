//
//  EnginesDriver.cpp
//  
    //
//  Created by Szymon Kordiaczyński on 24.08.2015.
//
//

#include "EnginesDriver.h"

using namespace v8;

Persistent<Function> EnginesDriver::constructor;

EnginesDriver::EnginesDriver(double value) : value_(value) {
}

EnginesDriver::~EnginesDriver() {
}

void EnginesDriver::Init(Handle<Object> exports) {
    Isolate* isolate = Isolate::GetCurrent();
    
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "EnginesDriver"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    
    
    // Prototype
    NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);
    
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "EnginesDriver"),
                 tpl->GetFunction());
}

void EnginesDriver::New(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    
    if (args.IsConstructCall()) {
        // Invoked as constructor: `new MyObject(...)`
        double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
        EnginesDriver* obj = new EnginesDriver(value);
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

void EnginesDriver::PlusOne(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    
    EnginesDriver* obj = ObjectWrap::Unwrap<EnginesDriver>(args.Holder());
    obj->value_ += 1;
    
    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}