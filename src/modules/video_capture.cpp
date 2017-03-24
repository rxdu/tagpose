/*
 * video_capture.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: rdu
 */

#include "video_capture.h"

using namespace al;

VideoCpature::VideoCpature()
{

}

VideoCpature::~VideoCpature()
{
	if(video_cap_.isOpened())
	{
		video_cap_.release();
		std::cout << "video capture device released." << std::endl;
	}
}

bool VideoCpature::OpenDefaultVideoDevice()
{
	return video_cap_.open(0);
}

bool VideoCpature::GetImageFrame(cv::OutputArray _dst)
{
	cv::Mat frame, gray;
	static clock_t loop_start_time_ = 0;
	clock_t last_start_time = loop_start_time_;
	loop_start_time_ = clock();
	clock_t exec_time = loop_start_time_ - last_start_time;
	std::cout << "***** Update rate: " << 1.0/(double(exec_time)/CLOCKS_PER_SEC) << " Hz." << std::endl;

	if(video_cap_.isOpened())
	{
		video_cap_.read(frame);

		if (frame.empty()) {
			std::cerr << "ERROR! blank frame grabbed\n";
			return false;
		}

		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	}
}
