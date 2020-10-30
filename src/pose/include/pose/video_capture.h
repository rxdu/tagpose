/* 
 * video_capture.h
 * 
 * Created on: Mar 23, 2017
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef VIDEO_CAPTURE_H
#define VIDEO_CAPTURE_H

#include <string>
#include "opencv2/opencv.hpp"

namespace al
{
class VideoCpature
{
public:
	VideoCpature();
	VideoCpature(int device_id);
    VideoCpature(std::string device_address);
	~VideoCpature();

	bool CaptureDeviceStarted() { return device_started_; };
	bool GetImageFrame(cv::OutputArray _dst);

private:
	// opencv devices
	bool device_started_;
	cv::VideoCapture video_cap_;
};
} // namespace al

#endif /* VIDEO_CAPTURE_H */
