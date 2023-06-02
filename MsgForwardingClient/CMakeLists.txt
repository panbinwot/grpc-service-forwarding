find_package(Threads)

set(SOURCES
    client.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

add_executable(forwardclient ${SOURCES})

target_link_libraries(forwardclient
    PRIVATE
        MsgForwarding
        MsgForwardingService
)