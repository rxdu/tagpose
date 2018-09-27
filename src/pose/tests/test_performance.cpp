/*
 * test_apriltag.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#include <ctime>
#include "opencv2/opencv.hpp"
#include "pose/video_capture.h"
#include "pose/apriltag_detection.h"

#define SHOW_IMG 1

using namespace al;
using namespace cv;

int main(int argc, char* argv[])
{
	ApriltagDetect ad;

	cv::Mat img;
	img = imread("../../data/test/sample.jpg",IMREAD_UNCHANGED);

	cv::Mat disp_img;

	clock_t last_start_time = clock();

	ad.LookForApriltags(img);

	clock_t exec_time = clock() - last_start_time;
	std::cout << "finished in : " << double(exec_time)/CLOCKS_PER_SEC << " s." << std::endl;

	imwrite("apriltag_result.jpg", img);
}


