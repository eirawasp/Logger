cmake_minimum_required(VERSION 3.13)

project(Logger VERSION 1.0 LANGUAGES CXX)


if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_library(Logger INTERFACE)

include_directories(includes)

set(SOURCE_EXE source/logger.cpp)

add_executable(logger ${SOURCE_EXE})	