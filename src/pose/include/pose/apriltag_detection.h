/* 
 * apriltag_detection.h
 * 
 * Created on: Mar 24, 2017
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef APRILTAG_DETECTION_H
#define APRILTAG_DETECTION_H

#include "apriltag.h"
#include "tag36h11.h"
#include "apriltag_utils/TagDetection.h"

namespace al
{
class ApriltagDetect
{
  public:
	ApriltagDetect();
	~ApriltagDetect();

	void SetTagSize(double sz) { tag_size_ = sz; };
	void SetCameraParams(double fx, double fy, double px, double py);
	void LookForApriltags(cv::InputArray _src, bool print_output = true);

  private:
	// apriltag variables
	apriltag_detector_t *apriltag_detector_;
	apriltag_family_t *apriltag_family_;

	// tag information
	double tag_size_;

	// camera intrinsic parameters
	double cam_fx_;
	double cam_fy_;
	double cam_px_;
	double cam_py_;

	// internal calculation
	AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t *det);
};
} // namespace al

#endif /* APRILTAG_DETECTION_H */
