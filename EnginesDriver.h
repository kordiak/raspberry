//
//  EnginesDriver.h
//  
//
//  Created by Szymon Kordiaczyński on 24.08.2015.
//
//

#ifndef ____EnginesDriver__
#define ____EnginesDriver__


//#include "Gpio.h"



#include <cstdio>

#include <node.h>
#include <node_object_wrap.h>

class EnginesDriver : public node::ObjectWrap
{
    
public:
    static void Init(v8::Handle<v8::Object> exports);
    
private:
    explicit EnginesDriver(double value = 0);
    ~EnginesDriver();
    
    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;
    double value_;
};






#endif /* defined(____EnginesDriver__) */
