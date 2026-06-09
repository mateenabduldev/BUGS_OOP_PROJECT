#pragma once
#include <opencv2/opencv.hpp>
#include "ICameraSource.h"

using namespace cv;

class CameraManager : public ICameraSource
{
private:
    VideoCapture cap;

public:
    CameraManager(int cameraNumber);
    bool readFrame(Mat& frame) override;
    ~CameraManager();
};
