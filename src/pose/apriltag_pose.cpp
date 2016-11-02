/*
 * apriltag_pose.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: rdu
 */

#include <iostream>
#include <string>

#include "apriltag_pose.h"
#include "apriltag_utils/PoseUtil.h"

using namespace apriltag_pose;
using namespace cv;

AprilTagPose::AprilTagPose()
{
	apriltag_family_ = tag36h11_create();
	apriltag_detector_ = apriltag_detector_create();

	apriltag_detector_add_family(apriltag_detector_, apriltag_family_);
}

AprilTagPose::~AprilTagPose()
{
	if(video_cap_.isOpened())
	{
		video_cap_.release();
		std::cout << "video capture device released." << std::endl;
	}

	apriltag_detector_destroy(apriltag_detector_);
	tag36h11_destroy(apriltag_family_);
}

bool AprilTagPose::OpenDefaultVideoDevice()
{
	return video_cap_.open(0);
}

AprilTags::TagDetection AprilTagPose::ConvertDetectionStruct(apriltag_detection_t* det)
{
	AprilTags::TagDetection tag_det;

	tag_det.id = det->id;
	tag_det.hammingDistance = det->hamming;

	tag_det.p[0] = std::make_pair<float,float>(det->p[0][0], det->p[0][1]);
	tag_det.p[1] = std::make_pair<float,float>(det->p[1][0], det->p[1][1]);
	tag_det.p[2] = std::make_pair<float,float>(det->p[2][0], det->p[2][1]);
	tag_det.p[3] = std::make_pair<float,float>(det->p[3][0], det->p[3][1]);

	tag_det.cxy = std::make_pair<float,float>(det->c[0], det->c[1]);
	tag_det.hxy = std::make_pair<float,float>(det->c[0], det->c[1]);

	for(int r = 0; r < det->H->nrows; r++)
		for(int c = 0; c < det->H->ncols; c++)
			tag_det.homography(r,c) = det->H->data[r * det->H->ncols + c];

	return tag_det;
}

bool AprilTagPose::GetPoseFromImage(cv::OutputArray _dst)
{
	cv::Mat frame, gray;

	if(video_cap_.isOpened())
	{
		video_cap_.read(frame);

		if (frame.empty()) {
			std::cerr << "ERROR! blank frame grabbed\n";
			return false;
		}

		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

		// Make an image_u8_t header for the Mat data
		// accessing cv::Mat (C++ data structure) in a C way
		image_u8_t im = { .width = gray.cols,
				.height = gray.rows,
				.stride = gray.cols,
				.buf = gray.data
		};

		// find all tags in the image frame
		zarray_t *detections = apriltag_detector_detect(apriltag_detector_, &im);
		//std::cout << zarray_size(detections) << " tags detected" << std::endl;

		// Draw detection outlines of each tag
		for (int i = 0; i < zarray_size(detections); i++) {
			apriltag_detection_t *det;
			zarray_get(detections, i, &det);

			/*------------------------------------------------------------*/
			AprilTags::TagDetection tag_det = ConvertDetectionStruct(det);

			Eigen::Vector3d translation;
			Eigen::Matrix3d rotation;
			tag_det.getRelativeTranslationRotation(0.16, 595, 595, 330, 340,
					translation, rotation);

			Eigen::Matrix3d F;
			F <<    1, 0,  0,
					0,  -1,  0,
					0,  0,  1;
			Eigen::Matrix3d fixed_rot = F*rotation;
			double yaw, pitch, roll;
			AprilTags::wRo_to_euler(fixed_rot, yaw, pitch, roll);

			std::cout << "  distance=" << translation.norm()
			        		 << "m, x=" << translation(0)
							 << ", y=" << translation(1)
							 << ", z=" << translation(2)
							 << ", yaw=" << yaw/M_PI*180.0
							 << ", pitch=" << pitch/M_PI*180.0
							 << ", roll=" << roll/M_PI*180.0
							 << std::endl;

			/*------------------------------------------------------------*/

			// draw 4 border lines on the tag image
			line(frame, Point(det->p[0][0], det->p[0][1]),
					Point(det->p[1][0], det->p[1][1]),
					Scalar(0, 0xff, 0), 2);
			line(frame, Point(det->p[0][0], det->p[0][1]),
					Point(det->p[3][0], det->p[3][1]),
					Scalar(0, 0, 0xff), 2);
			line(frame, Point(det->p[1][0], det->p[1][1]),
					Point(det->p[2][0], det->p[2][1]),
					Scalar(0xff, 0, 0), 2);
			line(frame, Point(det->p[2][0], det->p[2][1]),
					Point(det->p[3][0], det->p[3][1]),
					Scalar(0xff, 0, 0), 2);

			// add tag id to the image
			String text = std::to_string(det->id);
			int fontface = FONT_HERSHEY_SCRIPT_SIMPLEX;
			double fontscale = 1.0;
			int baseline;
			Size textsize = getTextSize(text, fontface, fontscale, 2, &baseline);
			putText(frame, text,
					Point(det->c[0]-textsize.width/2, det->c[1]+textsize.height/2),
					fontface, 1.0, Scalar(0xff, 0x99, 0), 2);
		}

		// free memory used for detection
		zarray_destroy(detections);

		// copy image so that it can be displayed outside
		_dst.create(frame.size(), frame.type());
		frame.copyTo(_dst);

		return true;
	}
	else
		return false;
}
