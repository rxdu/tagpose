/*
 * apriltag_detection.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: rdu
 */

#include "apriltag_detection.h"
#include "apriltag_utils/PoseUtil.h"

using namespace al;

ApriltagDetect::ApriltagDetect():
		tag_size_(0.064),
		cam_fx_(595),
		cam_fy_(595),
		cam_px_(330),
		cam_py_(340)
{
	apriltag_family_ = tag36h11_create();
	apriltag_detector_ = apriltag_detector_create();

	apriltag_detector_add_family(apriltag_detector_, apriltag_family_);
}

ApriltagDetect::~ApriltagDetect()
{
	apriltag_detector_destroy(apriltag_detector_);
	tag36h11_destroy(apriltag_family_);
}

AprilTags::TagDetection ApriltagDetect::ConvertDetectionStruct(apriltag_detection_t* det)
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

void ApriltagDetect::SetCameraParams(double fx, double fy, double px, double py)
{
	cam_fx_ = fx;
	cam_fy_ = fy;
	cam_px_ = px;
	cam_py_ = py;
}

void ApriltagDetect::LookForApriltags(cv::InputArray _src, bool print_output)
{
	cv::Mat frame =  _src.getMat();
	cv::Mat grey;
	cv::cvtColor(frame, grey, cv::COLOR_BGR2GRAY);

	// Make an image_u8_t header for the Mat data
	// accessing cv::Mat (C++ data structure) in a C way
	image_u8_t im = { .width = grey.cols,
			.height = grey.rows,
			.stride = grey.cols,
			.buf = grey.data
	};

	// find all tags in the image frame
	zarray_t *detections = apriltag_detector_detect(apriltag_detector_, &im);

	//std::cout << "image size: " << frame.rows << " , " << frame.cols << " ; tag detected: " << zarray_size(detections) << std::endl;

	// Draw detection outlines of each tag
	for (int i = 0; i < zarray_size(detections); i++) {
		apriltag_detection_t *det;
		zarray_get(detections, i, &det);

		AprilTags::TagDetection tag_det = ConvertDetectionStruct(det);

		Eigen::Vector3d translation;
		Eigen::Matrix3d rotation;
		tag_det.getRelativeTranslationRotation(tag_size_, cam_fx_, cam_fy_, cam_px_, cam_py_,
				translation, rotation);

		Eigen::Matrix3d F;
		F <<    1, 0,  0,
				0,  -1,  0,
				0,  0,  1;
		Eigen::Matrix3d fixed_rot = F*rotation;
		double yaw, pitch, roll;
		AprilTags::wRo_to_euler(fixed_rot, yaw, pitch, roll);

		if(print_output) {
			std::cout << " ------------------ " << std::endl;
			std::cout << "tag id: " << tag_det.id << std::endl;
			std::cout << "distance: " << translation.norm() << std::endl;
			std::cout << "translation: ( " <<  translation(0) << " , "
					<<  translation(1) << " , "
					<<  translation(2) << " )" << std::endl;
			std::cout << "rotation(rpy): ( " <<  roll/M_PI*180.0 << " , "
					<<  pitch/M_PI*180.0 << " , "
					<<  yaw/M_PI*180.0 << " )" << std::endl;

			// draw 4 border lines on the tag image
			tag_det.draw(frame);
		}
	}

	// free memory used for detection
	zarray_destroy(detections);
}

