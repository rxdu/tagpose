cmake_minimum_required(VERSION 2.8.11)
project(april_tag_pose)

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Config eigen include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/common/)

## Conditionally add source directories
find_package(OpenCV REQUIRED)

## Add source directories
#add_subdirectory(utils)   
add_subdirectory(apriltag)