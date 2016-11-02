# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add libraries
set(APRILTAG_POSE_LIB_SRC
  apriltag_pose.cpp
)
add_library(apriltag_pose STATIC ${APRILTAG_POSE_LIB_SRC})
target_link_libraries(apriltag_pose apriltags ${OpenCV_LIBS})

add_executable(test_apriltag opencv_demo.cc)
target_link_libraries(test_apriltag apriltags -pthread)
