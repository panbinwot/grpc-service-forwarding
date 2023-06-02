find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)


# Message Types as lib
set(PROTO_FILES
    MsgForwarding.proto
)

add_library(MsgForwarding ${PROTO_FILES})
target_link_libraries(MsgForwarding
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

target_include_directories(MsgForwarding PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Service files as lib
set(PROTO_SERVICE_FILES
    MsgForwardingServer.proto
)
add_library(MsgForwardingService ${PROTO_SERVICE_FILES})
target_link_libraries(MsgForwardingService
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
target_include_directories(MsgForwarding PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Generate those header, source files by protoc. I am using the plugin here. U can use COMMAND as they did in the example.
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET MsgForwarding LANGUAGE cpp)
protobuf_generate(TARGET MsgForwardingService LANGUAGE cpp)
protobuf_generate(
                TARGET MsgForwardingService
                LANGUAGE grpc 
                GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc 
                PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}"
)
