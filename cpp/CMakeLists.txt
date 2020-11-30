cmake_minimum_required (VERSION 3.10.2)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++14 -fPIC")

project (cpp)

ADD_SUBDIRECTORY(proto)
add_subdirectory(cppsdk)
add_subdirectory(example)