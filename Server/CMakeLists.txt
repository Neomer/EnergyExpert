cmake_minimum_required(VERSION 3.8)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

project(Server VERSION 0.0.1 DESCRIPTION "EnergyExpert server application")

include(pugixml)

include_directories("../")
include_directories("/")

set(SOURCE_EXE main.cpp)

add_executable(Server ${SOURCE_EXE})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Sdk)
TARGET_LINK_LIBRARIES(Server Sdk)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
