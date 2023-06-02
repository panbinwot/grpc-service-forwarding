cmake_minimum_required(VERSION 3.13)
project(MyGrpc LANGUAGES CXX)

set(CMAKE_MOUDLE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(proto)
add_subdirectory(MsgForwardingService)
add_subdirectory(MsgForwardingClient)