/*
 * camera.cpp
 *
 * Created on: Mar 23, 2017
 * Description:
 *
 * Copyright (c) 2018-2020 Ruixiang Du (rdu)
 */

#include "tagpose/camera.hpp"

namespace al {
Camera::Camera(int device_id) { device_started_ = video_cap_.open(device_id); }

Camera::Camera(std::string device_address) {
  device_started_ = video_cap_.open(device_address);
}

Camera::~Camera() {
  if (video_cap_.isOpened()) {
    video_cap_.release();
    std::cout << "video capture device released." << std::endl;
  }
}

bool Camera::GetImageFrame(cv::OutputArray _dst) {
  cv::Mat frame, gray;

  video_cap_.read(frame);

  if (frame.empty()) {
    std::cerr << "ERROR! blank frame grabbed\n";
    return false;
  }

  // copy image so that it can be displayed outside
  _dst.create(frame.size(), frame.type());
  frame.copyTo(_dst);

  return true;
}
}  // namespace al
