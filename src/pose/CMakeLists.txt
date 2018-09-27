cmake_minimum_required(VERSION 2.8.11)
project(al_modules)

# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add libraries
set(POSE_SRC
  src/video_capture.cpp
  src/apriltag_detection.cpp
  src/apriltag_pose.cpp
)
add_library(pose STATIC ${POSE_SRC})
target_link_libraries(pose apriltags apriltag_utils ${OpenCV_LIBS})
target_include_directories(pose PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
  PRIVATE src)

add_subdirectory(tests)
