/*
 * tag_detector.hpp
 *
 * Created on: Mar 24, 2017
 * Description:
 *
 * Copyright (c) 2018-2020 Ruixiang Du (rdu)
 */

#ifndef TAG_DETECTOR_HPP
#define TAG_DETECTOR_HPP

#include "apriltag.h"
#include "tag36h11.h"
// #include "apriltag_utils/TagDetection.h"

#include <opencv2/opencv.hpp>

namespace al {
class TagDetector {
 public:
  TagDetector();
  ~TagDetector();

  void SetTagSize(double sz) { tag_size_ = sz; };
  void SetCameraParams(double fx, double fy, double px, double py);
  void LookForApriltags(cv::InputArray _src, bool print_output = true);

 private:
  apriltag_family_t *apriltag_family_;
  apriltag_detector_t *apriltag_detector_;

  // tag information
  double tag_size_;

  // camera intrinsic parameters
  double cam_fx_;
  double cam_fy_;
  double cam_px_;
  double cam_py_;

  // internal calculation
  //   AprilTags::TagDetection ConvertDetectionStruct(apriltag_detection_t
  //   *det);
};
}  // namespace al

#endif /* TAG_DETECTOR_HPP */
