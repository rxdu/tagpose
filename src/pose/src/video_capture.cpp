/* 
 * video_capture.cpp
 * 
 * Created on: Mar 23, 2017
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */ 

#include "pose/video_capture.h"

using namespace al;

VideoCpature::VideoCpature()
{
	device_started_ = video_cap_.open(0);
}

VideoCpature::VideoCpature(int device_id)
{
	device_started_ = video_cap_.open(device_id);
}

VideoCpature::VideoCpature(std::string device_address){
    device_started_ = video_cap_.open(device_address);
}

VideoCpature::~VideoCpature()
{
	if (video_cap_.isOpened())
	{
		video_cap_.release();
		std::cout << "video capture device released." << std::endl;
	}
}

bool VideoCpature::GetImageFrame(cv::OutputArray _dst)
{
	cv::Mat frame, gray;

	video_cap_.read(frame);

	if (frame.empty())
	{
		std::cerr << "ERROR! blank frame grabbed\n";
		return false;
	}

	// copy image so that it can be displayed outside
	_dst.create(frame.size(), frame.type());
	frame.copyTo(_dst);

	return true;
}
