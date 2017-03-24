/*
 * PoseUtil.cc
 *
 *  Created on: Nov 2, 2016
 *      Author: rdu
 */

#include <apriltag_utils/PoseUtil.h>
#include <cmath>


namespace AprilTags{

#ifndef PI
const double PI = 3.14159265358979323846;
#endif
const double TWOPI = 2.0*PI;

/**
 * Normalize angle to be within the interval [-pi,pi].
 */
double standardRad(double t) {
  if (t >= 0.) {
    t = fmod(t+PI, TWOPI) - PI;
  } else {
    t = fmod(t-PI, -TWOPI) + PI;
  }
  return t;
}

/**
 * Convert rotation matrix to Euler angles
 */
void wRo_to_euler(const Eigen::Matrix3d& wRo, double& yaw, double& pitch, double& roll) {
    yaw = standardRad(std::atan2(wRo(1,0), wRo(0,0)));
    double c = std::cos(yaw);
    double s = std::sin(yaw);
    pitch = standardRad(std::atan2(-wRo(2,0), wRo(0,0)*c + wRo(1,0)*s));
    roll  = standardRad(std::atan2(wRo(0,2)*s - wRo(1,2)*c, -wRo(0,1)*s + wRo(1,1)*c));
}

}

