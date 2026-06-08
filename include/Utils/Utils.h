#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class Utils {
public:
    static void saveScreenshot(cv::Mat frame);
    static void drawFPS(cv::Mat& frame);
};
