/*
 * calib_image_capture.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: rdu
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "opencv2/opencv.hpp"

#include "pose/video_capture.h"

using namespace cv;
using namespace al;

int main(int argc, char* argv[])
{
	if( argc != 3 )
	{
		printf("usage: specify [a prefix to the image] [number of images to be captured] \n");
		return -1;
	}

	std::string img_prefix = argv[1];
	int img_num = std::stoi(argv[2]);

	Camera vc;

	if(vc.CaptureDeviceStarted()) {
		cv::Mat img;

		int img_count = 0;
		clock_t last_start_time = clock();
		while(true) {
			vc.GetImageFrame(img);

			imshow("Capture Image", img);
			waitKey(30);

			// this controls the capture to happen about every 5 seconds
			clock_t time_now = clock();
			clock_t exec_time = time_now - last_start_time;
			double elapsed_time = double(exec_time)/CLOCKS_PER_SEC*10;
			//std::cout << "time: " << exec_time << " , " << elapsed_time << std::endl;
			if(elapsed_time > 5.0) {
				last_start_time = time_now;


				std::string img_name = img_prefix+std::to_string(img_count++) + ".jpg";
				imwrite(img_name, img);
				std::cout << "Image " << img_count - 1 << " captured." << std::endl;

				if(img_count == img_num)
					break;
			}
		}
	}
	else
		std::cout << "failed to open capture device" << std::endl;
}


