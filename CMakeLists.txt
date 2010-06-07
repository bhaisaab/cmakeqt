#CMakeQt by Rohit Yadav<rohityadav89@gmail.com>
#Minimalistic CMake Build System for Qt

project(CMAKEQT) # Name of project

cmake_minimum_required(VERSION 2.6.0)
find_package(Qt4 REQUIRED)
add_definitions(${QT_DEFINITIONS})
link_directories(${QT4_LIB_DIR})
include_directories(${QT4_INCLUDE_DIR})

#Recursively add sub dirs
add_subdirectory(src)

