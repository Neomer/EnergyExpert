cmake_minimum_required(VERSION 3.8)

project(Sdk  VERSION 0.0.1 DESCRIPTION "EnergyExpert SDK library")

set(SOURCE_LIB Core/Data/IDataReader.cpp Core/Data/IDataReader.h
               export.h)


add_library(Sdk SHARED ${SOURCE_LIB})

include_directories("/")

set_target_properties(Sdk PROPERTIES VERSION ${PROJECT_VERSION})


# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(SDK_LIBRARY_EXPORT)
