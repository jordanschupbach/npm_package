#include <node.h>

// #include <mylib/addon.hpp>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::String;
using v8::Local;
using v8::Number;
using v8::Value;
using v8::Exception;

void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "hello world").ToLocalChecked());
}


void Sum(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  int i;
  double a=5.123; 
  double b = 9.1233;
  for(i =0; i< 1000000000; i++){
    a += b;
  }
  auto total = v8::Number::New(isolate, a);
  args.GetReturnValue().Set(total);
}


void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if(args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()
    ));
    return;
  }

  if(!args[0]->IsNumber() || !args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()
    ));
    return;
  }

  double value = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
  Local<Number> num = Number::New(isolate, value);
  args.GetReturnValue().Set(num);
}



void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "hello", Hello);
  NODE_SET_METHOD(exports, "sum", Sum);
  NODE_SET_METHOD(exports, "add", Add);
} 

NODE_MODULE(addon, Initialize);
