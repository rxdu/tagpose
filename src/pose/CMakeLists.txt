# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_apriltag opencv_demo.cc)
target_link_libraries(test_apriltag apriltags -pthread)
