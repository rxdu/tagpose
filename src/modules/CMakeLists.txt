cmake_minimum_required(VERSION 2.8.11)
project(al_modules)

# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add libraries
set(AL_MODULES_SRC
  video_capture.cpp
)
add_library(al_modules STATIC ${AL_MODULES_SRC})
target_link_libraries(al_modules apriltags apriltag_utils ${OpenCV_LIBS})

#add_executable(test_apriltag tests/test_pose.cpp)
#target_link_libraries(test_apriltag apriltags apriltag_pose -pthread)

#add_executable(test_apriltag tests/opencv_demo.cc)
#target_link_libraries(test_apriltag apriltags -pthread)
