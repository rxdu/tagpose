/*
 * apriltag_detect.h
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#ifndef MODULES_APRILTAG_DETECT_H_
#define MODULES_APRILTAG_DETECT_H_

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

private:
	// internal calculation
	AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t* det);

public:
	void FindApriltags(cv::InputArray _src, cv::OutputArray _dst);
};

}

#endif /* MODULES_APRILTAG_DETECT_H_ */
