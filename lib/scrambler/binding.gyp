{
  "targets": [
    {
      "target_name": "scrambler",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "src/scrambler.cc", "src/scramblers/3x3.cc" ],
      "include_dirs": [
         "<!@(node -p \"require('node-addon-api').include\")",
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
