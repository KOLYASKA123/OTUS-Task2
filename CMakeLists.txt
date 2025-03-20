cmake_minimum_required(VERSION 3.10)

project(ip_filter)

add_subdirectory(ip_filter)

add_executable(ip_filter main.cpp)

target_include_directories(ip_filter PUBLIC ip_filter)
target_link_libraries(ip_filter ip_filter_lib)
