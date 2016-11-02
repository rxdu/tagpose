# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

# Add libraries
set(APRILTAG_POSE_LIB_SRC
  apriltag_pose.cpp
)
add_library(apriltag_pose STATIC ${APRILTAG_POSE_LIB_SRC})
target_link_libraries(apriltag_pose apriltags apriltag_utils ${OpenCV_LIBS})

add_executable(test_apriltag tests/test_pose.cpp)
target_link_libraries(test_apriltag apriltags apriltag_pose -pthread)

#add_executable(test_apriltag tests/opencv_demo.cc)
#target_link_libraries(test_apriltag apriltags -pthread)
