#include <napi.h>

Napi::String Scramble(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  return Napi::String::New(env, "dupa");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "scramble"),
              Napi::Function::New(env, Scramble));

  return exports;
}

NODE_API_MODULE(scrambler, Init)