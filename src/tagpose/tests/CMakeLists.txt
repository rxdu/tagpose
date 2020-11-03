# tests
add_executable(test_apriltag_pose test_pose.cpp)
target_link_libraries(test_apriltag_pose pose -pthread)

#add_executable(test_apriltag tests/opencv_demo.cc)
#target_link_libraries(test_apriltag apriltags -pthread)

add_executable(test_videocap test_videocap.cpp)
target_link_libraries(test_videocap pose)

add_executable(test_apriltag test_apriltag.cpp)
target_link_libraries(test_apriltag pose -pthread)

add_executable(test_performance test_performance.cpp)
target_link_libraries(test_performance pose -pthread)
