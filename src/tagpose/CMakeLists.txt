# Dependent libraries
find_package(OpenCV REQUIRED)

# Add libraries
set(TAGPOSE_SRC
    src/camera.cpp
    # src/tag_detector.cpp
#   src/apriltag_detection.cpp
#   src/apriltag_pose.cpp
)
add_library(tagpose STATIC ${TAGPOSE_SRC})
target_link_libraries(tagpose apriltag ${OpenCV_LIBS})
target_include_directories(tagpose PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
    PRIVATE src)

# add_subdirectory(tests)
