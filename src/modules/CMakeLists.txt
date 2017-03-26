cmake_minimum_required(VERSION 2.8.11)
project(al_modules)

# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add libraries
set(AL_MODULES_SRC
  video_capture.cpp
  apriltag_detection.cpp
)
add_library(al_modules STATIC ${AL_MODULES_SRC})
target_link_libraries(al_modules apriltags apriltag_utils ${OpenCV_LIBS})

add_executable(test_videocap tests/test_videocap.cpp)
target_link_libraries(test_videocap al_modules ${OpenCV_LIBS})

add_executable(test_apriltag tests/test_apriltag.cpp)
target_link_libraries(test_apriltag al_modules ${OpenCV_LIBS}  -pthread)

add_executable(test_performance tests/test_performance.cpp)
target_link_libraries(test_performance al_modules ${OpenCV_LIBS}  -pthread)

#add_executable(test_apriltag tests/opencv_demo.cc)
#target_link_libraries(test_apriltag apriltags -pthread)
