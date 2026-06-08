#pragma once
#include "Mode.h"

class EllipseMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        drawer.drawEllipses(frame, faces);
    }
    std::string getName() override {
        return "Ellipse";
    }
};
