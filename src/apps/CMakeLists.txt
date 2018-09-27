cmake_minimum_required(VERSION 2.8.11)
project(al_apps)

# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add apps
add_executable(camera_calibration camera_calibration.cpp)
target_link_libraries(camera_calibration ${OpenCV_LIBS})

add_executable(calib_image_capture calib_image_capture.cpp)
target_link_libraries(calib_image_capture pose)

add_executable(apriltag_pose_demo apriltag_pose_demo.cpp)
target_link_libraries(apriltag_pose_demo pose -pthread)