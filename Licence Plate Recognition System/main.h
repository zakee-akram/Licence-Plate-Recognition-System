#pragma once
#ifndef MAIN_H
#define MAIN_H
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "plate.h"
#include<opencv2/imgproc.hpp>
#define SHOW_ALL_IMAGES
//void preProcess(cv::Mat orignal,cv::Mat grayScale, cv::Mat threshold, cv::Mat blur, cv::Mat canny);
Mat preProcess(Mat orignal);
std::vector<std::vector<Point>> getContours(Mat image);
void contourReduction1(std::vector<std::vector<Point>> contours, Mat image);
#endif 
