cmake_minimum_required (VERSION 3.10.2)

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra")
else()
    SET(CMAKE_CXX_FLAGS "-g -Wall -std=c++14 -fPIC")
endif(CMAKE_COMPILER_IS_GNUCXX)

project(cpp)

ADD_SUBDIRECTORY(proto)
add_subdirectory(cppsdk)
add_subdirectory(example)