/*
 * video_capture.h
 *
 *  Created on: Mar 23, 2017
 *      Author: rdu
 */

#ifndef MODULES_VIDEO_CAPTURE_H_
#define MODULES_VIDEO_CAPTURE_H_

#include "opencv2/opencv.hpp"

namespace al {

class VideoCpature
{
public:
	VideoCpature();
	VideoCpature(int device_id);
	~VideoCpature();


private:
	// opencv devices
	bool device_started_;
	cv::VideoCapture video_cap_;

public:
	bool CaptureDeviceStarted() { return device_started_; };
	bool GetImageFrame(cv::OutputArray _dst);
};

}

#endif /* MODULES_VIDEO_CAPTURE_H_ */
