#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class ICameraSource {
public:
    virtual bool readFrame(Mat& frame) = 0;
    virtual ~ICameraSource() = default;
};
