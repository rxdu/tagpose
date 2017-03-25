/*
 * test_apriltag.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#include <ctime>
#include "opencv2/opencv.hpp"
#include "video_capture.h"
#include "apriltag_detect.h"

#define SHOW_IMG 1

using namespace al;
using namespace cv;

int main(int argc, char* argv[])
{
	ApriltagDetect ad;

	cv::Mat img;
	img = imread("/home/rdu/Workspace/apriltag_localization/build/bin/sample.jpg",IMREAD_UNCHANGED);

	cv::Mat disp_img;

	clock_t last_start_time = clock();

	ad.FindApriltags(img);

	clock_t exec_time = clock() - last_start_time;
	std::cout << "finished in : " << double(exec_time)/CLOCKS_PER_SEC << " s." << std::endl;

	imwrite("apriltag_result.jpg", img);
}


