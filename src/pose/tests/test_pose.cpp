/*
 * test_pose.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: rdu
 */

#include "opencv2/opencv.hpp"

#include "apriltag_pose.h"

using namespace apriltag_pose;
using namespace cv;

int main(int argc, char* argv[])
{
	AprilTagPose apriltag_pose;

	namedWindow("Processed Image", WINDOW_NORMAL ); // WINDOW_AUTOSIZE

	if(apriltag_pose.OpenDefaultVideoDevice())
	{
		std::cout << "device opened" << std::endl;

		cv::Mat img_show;

		while(true)
		{
			apriltag_pose.GetPoseFromImage(img_show);

			imshow("Processed Image", img_show);
			if (waitKey(30) >= 0)
				break;
		}
	}

	waitKey(0);
}

