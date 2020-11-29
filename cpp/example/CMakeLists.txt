cmake_minimum_required (VERSION 3.10.2)

project (example)

include_directories("${CMAKE_CURRENT_LIST_DIR}/../cppsdk/include" "${CMAKE_CURRENT_LIST_DIR}/../cppsdk/lib/include" "${CMAKE_CURRENT_LIST_DIR}/../proto")

add_subdirectory(src)