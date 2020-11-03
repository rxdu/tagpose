/*
 * camera.hpp
 *
 * Created on: Mar 23, 2017
 * Description:
 *
 * Copyright (c) 2018-2020 Ruixiang Du (rdu)
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include "opencv2/opencv.hpp"

namespace al {
class Camera {
 public:
  Camera(int device_id = 0);
  Camera(std::string device_address);
  ~Camera();

  bool CaptureDeviceStarted() { return device_started_; };
  bool GetImageFrame(cv::OutputArray _dst);

 private:
  // opencv devices
  bool device_started_;
  cv::VideoCapture video_cap_;
};
}  // namespace al

#endif /* CAMERA_HPP */
