/*
 * apriltag_detection.h
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#ifndef MODULES_APRILTAG_DETECTION_H_
#define MODULES_APRILTAG_DETECTION_H_

#include "apriltag.h"
#include "tag36h11.h"
#include "apriltag_utils/TagDetection.h"

namespace al {

class ApriltagDetect {
public:
	ApriltagDetect();
	~ApriltagDetect();

private:
	// apriltag variables
	apriltag_detector_t* apriltag_detector_;
	apriltag_family_t* apriltag_family_;

	// tag information
	double tag_size_;

	// camera intrinsic parameters
	double cam_fx_;
	double cam_fy_;
	double cam_px_;
	double cam_py_;

private:
	// internal calculation
	AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t* det);

public:
	void SetTagSize(double sz) { tag_size_ = sz; };
	void SetCameraParams(double fx, double fy, double px, double py);
	void LookForApriltags(cv::InputArray _src, bool print_output = true);
};

}

#endif /* MODULES_APRILTAG_DETECTION_H_ */
