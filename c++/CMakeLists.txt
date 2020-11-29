cmake_minimum_required (VERSION 3.10.2)

project (cppsdk)

include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
find_library(sdk_lib sdk "${CMAKE_SOURCE_DIR}/lib/bin")   

add_subdirectory(src)