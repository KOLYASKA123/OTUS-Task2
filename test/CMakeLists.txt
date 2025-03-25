cmake_minimum_required(VERSION 3.10)

set(This Tests)

set(Sourses
    Tests.cpp
)

add_executable(${This} ${Sourses})

target_include_directories(${This} PUBLIC "../ip_filter")


target_link_libraries(${This} PUBLIC
    gtest_main
    version
    ip_filter_lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
