cmake_minimum_required(VERSION 3.8)

project(Server VERSION 0.0.1 DESCRIPTION "EnergyExpert server application")

include_directories("../Sdk/")
include_directories("/")

set(SOURCE_EXE main.cpp)

add_executable(Server ${SOURCE_EXE})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Sdk)
TARGET_LINK_LIBRARIES(Server Sdk)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
