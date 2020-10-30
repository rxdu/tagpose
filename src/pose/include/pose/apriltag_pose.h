/* 
 * apriltag_pose.h
 * 
 * Created on: Nov 1, 2016
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef APRILTAG_POSE_H
#define APRILTAG_POSE_H

#include "opencv2/opencv.hpp"

#include "Eigen/Core"
#include "Eigen/Geometry"

#include "apriltag.h"
#include "tag36h11.h"
#include "apriltag_utils/TagDetection.h"

namespace apriltag_pose
{
class AprilTagPose
{
  public:
	AprilTagPose();
	~AprilTagPose();

	// video capture device operations
	bool OpenDefaultVideoDevice();
    bool OpenVideoDevice(std::string device);

	// pose estimation from apriltags
	bool GetPoseFromImage(cv::OutputArray _dst);

  private:
	// opencv devices
	cv::VideoCapture video_cap_;

	// apriltag variables
	apriltag_detector_t *apriltag_detector_;
	apriltag_family_t *apriltag_family_;

	clock_t loop_start_time_;

	// internal calculation
	AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t *det);
};
} // namespace apriltag_pose

#endif /* APRILTAG_POSE_H */
