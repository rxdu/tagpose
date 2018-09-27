cmake_minimum_required(VERSION 2.8.11)
project(apriltag_utils)

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Conditionally add source directories
find_package(OpenCV REQUIRED)

# Add libraries
set(UTILS_SRC
	src/MathUtil.cc
	src/TagDetection.cc
	src/PoseUtil.cc
)
add_library(apriltag_utils STATIC ${UTILS_SRC})
target_link_libraries(apriltag_utils ${OpenCV_LIBRARIES})
target_include_directories(apriltag_utils PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE src)
