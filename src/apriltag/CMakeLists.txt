cmake_minimum_required(VERSION 2.8.11)
project(april_tag)

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Config eigen include directories
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/common/)

## Conditionally add source directories
find_package(OpenCV REQUIRED)

# Add libraries
set(APRILTAGS_LIB_SRC
	tag16h5.c
	tag25h7.c
	tag25h9.c
	apriltag.c
	tag36h10.c
	tag36h11.c
	tag36artoolkit.c
	apriltag_quad_thresh.c
	common/g2d.c
	common/pnm.c
	common/matd.c
	common/svd22.c
	common/zhash.c
	common/getopt.c
	common/zarray.c
	common/image_u8.c
	common/zmaxheap.c
	common/image_f32.c
	common/time_util.c
	common/unionfind.c
	common/homography.c
	common/image_u8x3.c
	common/workerpool.c
	common/string_util.c
)
add_library(apriltags STATIC ${APRILTAGS_LIB_SRC})
set_target_properties(apriltags PROPERTIES COMPILE_FLAGS "-std=gnu99")
target_link_libraries(apriltags ${OpenCV_LIBRARIES})

#add_executable(apriltag_demo example/apriltag_demo.c)
#set_target_properties(apriltag_demo PROPERTIES COMPILE_FLAGS "-std=gnu99")
#target_link_libraries(apriltag_demo apriltags -pthread -lm)

#add_executable(opencv_demo example/opencv_demo.cc)
#target_link_libraries(opencv_demo apriltags -pthread)
