add_library(cppsdk SHARED sdk.cpp protos)

target_include_directories (cppsdk PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(cppsdk PRIVATE "${sdk_lib}")