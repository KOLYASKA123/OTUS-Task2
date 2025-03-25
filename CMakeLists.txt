cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(gtest_force_shared_crt ON)
set(INC_DIRS ip_filter ${CMAKE_BINARY_DIR})

project(ip_filter VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

add_subdirectory(ip_filter)

add_executable(ip_filter main.cpp)
add_library(version version.cpp)

target_include_directories(ip_filter PUBLIC ${INC_DIRS})
target_link_libraries(ip_filter ip_filter_lib version)

include_directories(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})

install(TARGETS ip_filter RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nikolas")

include(CPack)

enable_testing()

add_subdirectory(googletest)

add_subdirectory(test)