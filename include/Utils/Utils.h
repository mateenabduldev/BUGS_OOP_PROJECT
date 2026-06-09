#pragma once
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;

class Utils {
public:
    static void saveScreenshot(Mat frame);
    static void drawFPS(Mat& frame);
};
