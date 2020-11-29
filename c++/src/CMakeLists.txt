add_library(cppsdk SHARED sdk.cpp)

target_include_directories (cppsdk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cppsdk PRIVATE "${sdk_lib}")