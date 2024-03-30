cmake_minimum_required(VERSION 3.15)

project(clog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    message(STATUS "building for: debugging")
    set(CXX_FORMAT_SIGNEDNESS "-Wformat-signedness")
    set(CXX_FORMAT_SECURITY "-Werror=format-security")
    set(CXX_STACK_PROTECTOR "-fstack-protector-all")
    set(CMAKE_CXX_FLAGS "-g -Wall")
ELSE()
    message(STATUS "building for: release")
    set(CMAKE_CXX_FLAGS "-O2")
ENDIF()

include_directories(${CMAKE_SOURCE_DIR}/include/clog)
add_subdirectory(tests)