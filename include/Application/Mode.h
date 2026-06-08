#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "ShapeDrawer/ShapeDrawer.h"

class Mode {
public:
    virtual void draw(ShapeDrawer& drawer, cv::Mat& frame, std::vector<cv::Rect>& faces) = 0;
    virtual std::string getName() = 0;
    virtual ~Mode() {}
};
