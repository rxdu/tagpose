cmake_minimum_required(VERSION 2.8.11)
project(april_tag_utils)

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Config eigen include directories
include_directories(${PROJECT_SOURCE_DIR})

## Conditionally add source directories
find_package(OpenCV REQUIRED)

# Add libraries
set(APRILTAG_UTILS_LIB_SRC
	MathUtil.cc
	TagDetection.cc
	PoseUtil.cc
)
add_library(apriltag_utils STATIC ${APRILTAG_UTILS_LIB_SRC})
#set_target_properties(apriltags PROPERTIES COMPILE_FLAGS "-std=gnu99")
target_link_libraries(apriltag_utils ${OpenCV_LIBRARIES})
