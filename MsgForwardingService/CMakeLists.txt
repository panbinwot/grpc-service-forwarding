find_package(Threads)

set(SOURCES
    server.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

add_executable(forwardserver ${SOURCES})

target_link_libraries(forwardserver
    PRIVATE
        MsgForwarding
        MsgForwardingService
)