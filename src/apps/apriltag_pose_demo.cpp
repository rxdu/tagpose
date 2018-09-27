/*
 * test_pose.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: rdu
 */

#include "opencv2/opencv.hpp"

#include "pose/apriltag_pose.h"

using namespace apriltag_pose;
using namespace cv;

int main(int argc, char* argv[])
{
	AprilTagPose apriltag_pose;

	// first open device
	if(apriltag_pose.OpenDefaultVideoDevice())
		std::cout << "device opened, hold any key to exit" << std::endl;
	else
		return -1;

	// then start a loop for capture and detection
	cv::Mat img_show;
	namedWindow("Processed Image", WINDOW_NORMAL ); // WINDOW_AUTOSIZE

	while(true)
	{
		apriltag_pose.GetPoseFromImage(img_show);

		imshow("Processed Image", img_show);
		if (waitKey(30) >= 0)
			continue;
	}

	return 0;
}

