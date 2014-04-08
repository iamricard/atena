# Author: Ricard Sole
# Date: 30 March 2014

# CMake minimum version
cmake_minimum_required(VERSION 2.8)

# Project Name
project(Atena)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Box2D REQUIRED)

# Add ./src directory
add_subdirectory(src)