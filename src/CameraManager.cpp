#include "CameraManager/CameraManager.h"
#include <iostream>

using namespace std;
using namespace cv;

CameraManager::CameraManager(int cameraNumber) {

    if (cameraNumber < 0)                                    
        throw runtime_error("Invalid camera number!");

    cap.open(cameraNumber);

    if (!cap.isOpened()) {
        throw runtime_error("Camera could not open!");
    }
}

bool CameraManager::readFrame(Mat& frame) {

    if (!cap.isOpened())                                     
        throw runtime_error("Camera is not opened!");

    cap.read(frame);

    return !frame.empty();
}

CameraManager::~CameraManager() {
    cap.release();
}