/*
 * apriltag_pose.h
 *
 *  Created on: Nov 1, 2016
 *      Author: rdu
 */

#ifndef POSE_APRILTAG_POSE_H_
#define POSE_APRILTAG_POSE_H_

#include "opencv2/opencv.hpp"

#include "Eigen/Core"
#include "Eigen/Geometry"

#include "apriltag.h"
#include "tag36h11.h"
#include "apriltag_utils/TagDetection.h"

namespace apriltag_pose {

class AprilTagPose
{
public:
	AprilTagPose();
	~AprilTagPose();

private:
	// opencv devices
	cv::VideoCapture video_cap_;

	// apriltag variables
	apriltag_detector_t* apriltag_detector_;
	apriltag_family_t* apriltag_family_;

private:
	// internal calculation
	AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t* det);

public:
	// video capture device operations
	bool OpenDefaultVideoDevice();

	// pose estimation from apriltags
	bool GetPoseFromImage(cv::OutputArray _dst);
};

}

#endif /* POSE_APRILTAG_POSE_H_ */
