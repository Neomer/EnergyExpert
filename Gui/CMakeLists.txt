cmake_minimum_required(VERSION 3.8)

project(Gui LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "EnergyExpert Gui library")

set(GUI_SOURCE_LIB export.h
                   Application/Application.cpp Application/Application.h
                   Widgets/AbstractWidget.cpp Widgets/AbstractWidget.h
                   Widgets/Window.cpp Widgets/Window.h)


add_library(Gui SHARED ${GUI_SOURCE_LIB})
add_compile_definitions(GUI_LIBRARY_EXPORT)
target_link_libraries(${TARGET} Gui)
TARGET_LINK_LIBRARIES(Gui Sdk)
set_target_properties(Gui PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET Sdk PROPERTY CXX_STANDARD 17)

include_directories("/")
include_directories("../")

set_target_properties(Sdk PROPERTIES VERSION ${PROJECT_VERSION})

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
