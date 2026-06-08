#pragma once
#include "Mode.h"

class RectangleMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        drawer.drawRectangles(frame, faces);
    }
    std::string getName() override {
        return "Rectangle";
    }
};
