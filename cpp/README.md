# C++ Telerobotics SDK
This folder contains source code for an example project that connects to telerobotics services.

## Setup
0. Install [protobuf](https://grpc.io/docs/protoc-installation/)
1. Get a copy of `libsdk.dll` from Ryan and place it in ```cppsdk/lib/bin/libsdk.dll``` (.so on Linux systems)
2. Run `cmake .` in the root of the cpp directory
3. Run `make` in the root of the cpp directory
4. Run `example/src/example`