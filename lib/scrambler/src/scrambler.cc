#include <napi.h>
#include "scramblers.h"
#include <string>

Napi::Value Scrambler(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() != 1)
  {
    Napi::TypeError::New(env, "No cube size passed").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber())
  {
    Napi::TypeError::New(env, "Passed cube size is not a number").ThrowAsJavaScriptException();
    return env.Null();
  }

  int cubeSize = info[0].As<Napi::Number>().Int32Value();
  std::string generatedAlgorithm;

  switch (cubeSize)
  {
  case 3:
    generatedAlgorithm = scramblers::gen3x3();
    break;
  default:
    Napi::Error::New(env, "Unsupported cube size").ThrowAsJavaScriptException();
    return env.Null();
  }

  return Napi::String::New(env, generatedAlgorithm);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  return Napi::Function::New(env, Scrambler);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);