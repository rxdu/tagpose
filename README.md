# apriltag-pose

This library provides a light C++ wrapper of the AprilTag library to extract pose information from tags.

## 1. Development environment

* Ubuntu >= 14.04 64-bit (MacOS should also work, if you know how to configure it)
* GCC >= 4.8.4

## 2. Install dependencies

* Building tools, Git, CMake
```
$ sudo apt-get install build-essential
$ sudo apt-get install git
$ sudo apt-get install cmake
```

* OpenCV

Used to capture images from camera and basic image processing and display.

```
$ sudo apt-get install libopencv-dev
```

* Eigen

Header-only library used for linear algebra. Eigen 3.2.10 source included with this project.

## 3. Compile Code

* Clone source code from GitHub, assume your workspace is located at: ~/Workspace
```
$ cd ~/Workspace
$ git clone https://github.com/rxdu/apriltag_localization.git
```

* Build from terminal
```
$ cd ~/Workspace/apriltag_localization
$ mkdir build
$ cd build
$ cmake ../src
$ make
```

## 4. Use Eclipse with the Project

To generate project configurations for Eclipse, you need to pass in additional arguments to the "cmake" command.

```
$ cmake -G"Eclipse CDT4 - Unix Makefiles" ../src
```

If you want to compile code with Debug symbols, use the following command

```
$ cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../src
```

## Reference

* [OpenCV Camera Calibration](http://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html)
