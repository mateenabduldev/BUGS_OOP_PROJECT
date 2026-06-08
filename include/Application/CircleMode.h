#pragma once
#include "Mode.h"

class CircleMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        drawer.drawCircles(frame, faces);
    }
    std::string getName() override {
        return "Circle";
    }
};
