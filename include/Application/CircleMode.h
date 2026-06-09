#pragma once
#include "Mode.h"

using namespace cv;
using namespace std;

class CircleMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, Mat& frame, vector<Rect>& faces) override {
        drawer.drawCircles(frame, faces);
    }
    string getName() override {
        return "Circle";
    }
};
