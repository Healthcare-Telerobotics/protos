set(CMAKE_PREFIX_PATH
	"D:/apps/vcpkg/installed/x64-windows"
	"${CMAKE_PREFIX_PATH}"
	)
# set(Protobuf_DEBUG ON)

INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_LIST_DIR}/../../protos")

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HDRS "${CMAKE_CURRENT_LIST_DIR}/../../protos/common.proto")

#ADD_LIBRARY(proto ${PROTO_HEADER} ${PROTO_SRC})

#target_link_libraries(proto ${Protobuf_LIBRARIES})