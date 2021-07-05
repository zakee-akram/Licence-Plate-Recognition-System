#include <iostream>
#include "main.h"
#include "plate.h"
using namespace cv;
int main() {
    //Set Image
    Mat orignal = imread("plate1.jpg");
#ifdef SHOW_ALL_IMAGES
    imshow("Plate", orignal);
#endif
    //Process the orignal image
    Mat processedImage = preProcess(orignal);
    waitKey(0);
}
Mat preProcess(Mat orignal) {
    //, Mat grayScale, Mat threshold, Mat blur, Mat canny
    //Value to return
    Mat processedImage;
    //Make the orignal image a grayscale
    cvtColor(orignal, orignal, COLOR_BGR2GRAY);
    processedImage = orignal;
    imshow("ProcessedImage", processedImage);
    return processedImage;
}


