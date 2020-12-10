# C++ Telerobotics SDK
This folder contains source code for an example project that connects to telerobotics services.

## Windows Setup
1. Get a copy of `libsdk.dll` from Ryan and place it in ```cppsdk/lib/bin/libsdk.dll```
1. Install a C++ compiler. e.g. [Mingw-w64](http://mingw-w64.org/doku.php)
1. Install the latest version of [protobuf](https://github.com/protocolbuffers/protobuf/blob/master/src/README.md)
1. Add protoc to PATH
1. Build the protos
```shell
$ cd proto
$ mkdir build
$ protoc -I=/path/to/protobuf/includes -I=../../protos --cpp_out=build common.proto

# If you used vcpkg to install protobuf, your command might look something like this
# $ protoc -I=D:/apps/vcpkg/installed/x64-windows/include -I=../../protos --cpp_out=build common.proto
```
6. Build the cpp sdk wrapper
```shell
$ cd cppsdk
$ mkdir bin
$ g++ -Wall -m32 -std=c++17 -fPIC -I /path/to/protobuf/includes -I include -I lib/include -I ../proto/build -c src/sdk.cpp -o src/sdk.o
$ g++ -shared -Wall -m64 -std=c++17 -fPIC -LD:\apps\vcpkg\installed\x64-windows\lib -Llib -lsdk -I D:/apps/vcpkg/installed/x64-windows/include -I include -I lib/include -I ../proto/build -o bin/libcppsdk.dll src/sdk.cpp
```
1. Run `example/src/example`


D:/apps/vcpkg/installed/x64-windows/include