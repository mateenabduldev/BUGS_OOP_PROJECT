#pragma once
#include <opencv2/opencv.hpp>
#include "ICameraSource.h"

class CameraManager : public ICameraSource
{
private:
    cv::VideoCapture cap;

public:
    CameraManager(int cameraNumber);
    bool readFrame(cv::Mat& frame) override;
    ~CameraManager();
};
