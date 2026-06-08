#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "CameraManager/CameraManager.h"
#include "FaceDetector/FaceDetector.h"
#include "ShapeDrawer/ShapeDrawer.h"
#include "Utils/Utils.h"
#include "Utils/Logger.h"

#include "Mode.h"
#include "RectangleMode.h"
#include "CircleMode.h"
#include "EllipseMode.h"

class Application {

private:

    CameraManager camera;
    FaceDetector detector;
    ShapeDrawer drawer;

    Logger logger;

    Mode* currentMode;

    RectangleMode rectangleMode;
    CircleMode circleMode;
    EllipseMode ellipseMode;

    cv::Mat frame;

public:

    Application();

    void processInput(char key);

    void run();

    ~Application();
};
