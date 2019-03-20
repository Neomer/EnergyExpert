cmake_minimum_required(VERSION 3.8)

project(Client  VERSION 0.0.1 DESCRIPTION "EnergyExpert Client desktop application")

include_directories("../")
include_directories("/")

set(SOURCE_EXE main.cpp)

add_executable(Client ${SOURCE_EXE})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Sdk)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Gui)

TARGET_LINK_LIBRARIES(Client Sdk Gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
