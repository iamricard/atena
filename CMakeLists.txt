# Author: Ricard Sole
# Date: 30 March 2014

# CMake minimum version
cmake_minimum_required(VERSION 2.8)

# Project Name
project(Atena)

# Add non-cmake projects
include(ExternalProject)
ExternalProject_Add(
    SDL2_image
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/SDL2_image-2.0.0
    CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/SDL2_image-2.0.0/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/src/lib/SDL2_image-2.0.0
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/SDL2_image-2.0.0
    BUILD_COMMAND make
    BUILD_IN_SOURCE 1
)

# Add ./src directory
add_subdirectory(src)