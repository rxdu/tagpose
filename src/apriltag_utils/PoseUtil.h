/*
 * PoseUtil.h
 *
 *  Created on: Nov 2, 2016
 *      Author: rdu
 */

#ifndef APRILTAG_UTIL_POSEUTIL_H_
#define APRILTAG_UTIL_POSEUTIL_H_

#include <Eigen/Dense>

namespace AprilTags {

double standardRad(double t);
void wRo_to_euler(const Eigen::Matrix3d& wRo, double& yaw, double& pitch, double& roll);

}

#endif /* APRILTAG_UTIL_POSEUTIL_H_ */
