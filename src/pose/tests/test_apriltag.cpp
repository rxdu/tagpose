/*
 * test_apriltag.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#include "opencv2/opencv.hpp"
#include "pose/video_capture.h"
#include "pose/apriltag_detection.h"

#define SHOW_IMG 1

using namespace al;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCpature vc;
	ApriltagDetect ad;

	//ad.SetCameraParams(816, 816, 319.5, 239.5);
	ad.SetCameraParams(181.9, 181.9, 319.5, 239.5);
	ad.SetTagSize(0.063);

	clock_t loop_start_time_ = 0;

	if(vc.CaptureDeviceStarted()) {
		cv::Mat img;
		cv::Mat disp_img;

		while(true) {

			clock_t last_start_time = loop_start_time_;
			loop_start_time_ = clock();
			clock_t exec_time = loop_start_time_ - last_start_time;
			std::cout << "***** Update rate: " << 1.0/(double(exec_time)/CLOCKS_PER_SEC) << " Hz." << std::endl;

			vc.GetImageFrame(img);
			ad.LookForApriltags(img);

#ifdef SHOW_IMG
			imshow("Processed Image", img);
			if (waitKey(30) >= 0)
				continue;
#endif
		}
	}
	else
		std::cout << "failed to open capture device" << std::endl;
}


