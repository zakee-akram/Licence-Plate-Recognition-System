#include <iostream>
#include "main.h"
#include "plate.h"

using namespace cv;
void info() {
    std::cout << "\t\t\t:::::Licence Plate System:::::\n " << "\t This sytem is purely to help me develop my c++ plus skills and learn opencv.\n" <<
        "\t Therefore the commenting is done in a more teaching method to help me.\n";
}
int main() {
    info();
    //The image that is being checked. 
    Mat orignal = imread("plates/plate1.jpg");
#ifdef SHOW_ALL_IMAGES
    imshow("OrignalImage", orignal);
#endif
    //Preprocess the orignal image.
    Mat processedImage = preProcess(orignal);
    //Gets the contours of the image.
    std::vector<std::vector<Point>> contours = getContours(processedImage);
    //Calls contourReduction1 to try and find plate.
    contourReduction1(contours, orignal);
    waitKey(0);
}

Mat preProcess(Mat orignal) {
    //Value to return at end of function. 
    Mat processedImage;
    //Make the orignal image a grayscale to alloy the threshold to work since it only accepts greyscale. 
    cvtColor(orignal, orignal, COLOR_BGR2GRAY);
#ifdef SHOW_ALL_IMAGES
    imshow("GreyScale", orignal);
#endif
    processedImage = orignal;
    //Applies Gaussian blur to help remove some of the high frequency edges in the image.
    Size blurSize = Size(5, 5);
    GaussianBlur(orignal, orignal, blurSize, 0);
#ifdef SHOW_ALL_IMAGES
    imshow("GaussianBlur", orignal);
#endif
    //Applies a threshold effect to the image. Technique that helps show foreground objects whilst removing things we dont need like the background.
    adaptiveThreshold(orignal, orignal, 255.0, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 19, 9);
#ifdef SHOW_ALL_IMAGES
    imshow("Threshold", orignal);
#endif
    //Final processed image to be returned for next steps. 
    return processedImage;
}

std::vector<std::vector<Point>> getContours(Mat image) {
    //Colours that are used when drawing the image.RGB.
    Scalar white = Scalar(255.0, 255.0, 255.0);
    Scalar black = Scalar(0.0, 0.0, 0.0);
    //Vector that stores all the contours. Just a dynamic array basically. 
    std::vector<std::vector<Point> > contours;
    //Find the contours in the image and outputs them to the vector.
    findContours(image, contours, RETR_LIST, CHAIN_APPROX_NONE);
    //New image that we will draw the contours onto and display. 
    Mat contourImage(image.size(), CV_8UC3, Scalar(0, 0, 0));
    return contours;

    //
    //    std::vector<std::vector<Point>> conPoly(contours.size());
    //    std::vector<Point> biggest;
    //    int maxArea = 0;
    //    std::vector<Rect> boundRect(contours.size());
    //
    //    for (size_t i = 0; i < contours.size(); i++) {
    //        cv::drawContours(contourImage, contours, i, white);
    //
    //        int area = contourArea(contours[i]);
    //        std::string objectType;
    //        if (area > 1000) {
    //            float peri = arcLength(contours[i], true);
    //            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
    //            if (area > maxArea && conPoly[i].size() == 4) {
    //                drawContours(image, conPoly, i, Scalar(255, 0, 255), 5);
    //                biggest = { conPoly[i][0],conPoly[i][1] ,conPoly[i][2] ,conPoly[i][3] };
    //                maxArea = area;
    //            }
    //            //drawContours(imgOriginal, 
    //            //drawContours(image, conPoly, i, Scalar(255, 0, 255), 2);
    //            rectangle(image, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
    //        }
    //
    //    }
    //#ifdef SHOW_ALL_IMAGES
    //    cv::imshow("Contours", contourImage);
    //#endif
    //
    //
    //
    //
    //    std::cout << "Current Amount Of Contours: " << contours.size() << "\n";
    //    cv::Rect boundingRect;
    //    std::vector<Point> vectorOfPossibleChars;
    //    std::vector<Rect> Rect(contours.size());
    //    std::vector<std::vector<Point> > Newcontours;
    //
    //    for (auto& contour : contours) {
    //        boundingRect = cv::boundingRect(contour);
    //        double aspect = (float)boundingRect.width / (float)boundingRect.height;
    //        if (boundingRect.area() > 80 && boundingRect.width > 4
    //            && boundingRect.height > 8 && 0.15 < aspect && aspect < 2) {
    //            Newcontours.push_back(contour);
    //        }
    //    }
    //    std::cout << "New Amount Of Contours: " << Newcontours.size() << "\n";
    //
    //    Mat newImage;
    //    newImage = Mat(image.size(), CV_8UC3, black);
    //    drawContours(newImage, Newcontours, -1, white);
    //    imshow("ContourReduction", newImage);
    //
    //
    //
    //
    //
    //
    //
    //
    //    std::vector<Point> newPoints;
    //    std::vector<int>  sumPoints, subPoints;
    //
    //    for (int i = 0; i < 4; i++)
    //    {
    //        sumPoints.push_back(biggest[i].x + biggest[i].y);
    //        subPoints.push_back(biggest[i].x - biggest[i].y);
    //    }
    //    newPoints.push_back(biggest[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); // 0
    //    newPoints.push_back(biggest[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //1
    //    newPoints.push_back(biggest[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //2
    //    newPoints.push_back(biggest[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); //3
    //    Mat testImage;
    //    float w = image.size[1];
    //    float h = image.size[0];
    //    Point2f src[4] = { newPoints[0],newPoints[1],newPoints[2],newPoints[3] };
    //    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
    //    Mat matrix = getPerspectiveTransform(src, dst);
    //    warpPerspective(contourImage, testImage, matrix, Point(w, h));
    //#ifdef SHOW_ALL_IMAGES
    //    imshow("OtherWayWarped", testImage);
    //#endif
















        //********************************


        //std::vector<std::vector<Point> > Secondcontours;
        //Mat TestImage2 = preProcess(testImage);
        //findContours(TestImage2, Secondcontours, RETR_LIST, CHAIN_APPROX_NONE);
        //std::cout << "Current Amount Of Contours: " << Secondcontours.size() << "\n";

        //cv::Rect boundingRect;
        //std::vector<Point> vectorOfPossibleChars;
        //std::vector<Rect> Rect(Secondcontours.size());
        //std::vector<std::vector<Point> > Newcontours;

        //for (auto& contour : Secondcontours) {
        //    boundingRect = cv::boundingRect(contour);
        //    double aspect = (float)boundingRect.width / (float)boundingRect.height;
        //    if (boundingRect.area() > 80 && boundingRect.width > 2
        //        && boundingRect.height > 8 && 0.25 < aspect && aspect < 1.0) {
        //        Newcontours.push_back(contour);
        //    }
        //}
        //std::cout << "New Amount Of Contours: " << Newcontours.size() << "\n";

        //Mat newImage;
        //newImage = Mat(image.size(), CV_8UC3, black);
        //drawContours(newImage, Newcontours, -1, white);
        //imshow("Test2", newImage);

}

void contourReduction1(std::vector<std::vector<Point>> contours, Mat image) {
    //Shows the contours without reduction.
    std::cout << "Current Amount Of Contours: " << contours.size() << "\n";
    //Sets the needed variables. Bounding Rectangle sets area of interest with rectangle. 
    cv::Rect rect;
    //2d vector to store the new contours.
    std::vector<std::vector<Point> > newContours;
    //Loops through all the countours checking if they meet the requirements to be considered not redundant.
    for (auto& contour : contours) {
        //Focuses on contour to check
        rect = cv::boundingRect(contour);
        //Calculate the aspect ration of that contour.
        double aspect = (float)rect.width / (float)rect.height;
        //If satisfies the loop then it could be a possible contour else the contour is ignored.
        if (rect.area() > 80 && rect.width > 4
            && rect.height > 8 && 0.15 < aspect && aspect < 2) {
            newContours.push_back(contour);
        }
    }
    //Shows the amount of countours left after reduction process.
    std::cout << "New Amount Of Contours: " << newContours.size() << "\n";

#ifdef SHOW_ALL_IMAGES
    //Draws the new contours to an image.
    Mat newImage = Mat(image.size(), CV_8UC3, Scalar(0.0, 0.0, 0.0));
    drawContours(newImage, newContours, -1, Scalar(255.0, 255.0, 255.0));
    imshow("ContourReduction", newImage);
#endif
}

