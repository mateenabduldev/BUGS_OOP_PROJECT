#pragma once
#include <opencv2/opencv.hpp>

class ICameraSource {
public:
    virtual bool readFrame(cv::Mat& frame) = 0;
    virtual ~ICameraSource() = default;
};
