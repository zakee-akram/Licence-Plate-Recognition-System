#pragma once
#ifndef PLATE_H
#define PLATE_H
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
class plate {
public:
    Mat orignal;
    Mat grayScale; 
    Mat threshold;
    Mat blur;
    Mat canny;
};
#endif