cmake_minimum_required (VERSION 3.10.2)

project (cppsdk)

include_directories(include "${CMAKE_CURRENT_LIST_DIR}/lib/include" "${CMAKE_CURRENT_LIST_DIR}/../proto")
find_library(sdk_lib sdk "${CMAKE_CURRENT_LIST_DIR}/lib/bin")   

add_subdirectory(src)