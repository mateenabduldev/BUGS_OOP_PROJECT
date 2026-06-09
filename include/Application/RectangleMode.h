#pragma once
#include "Mode.h"

using namespace cv;
using namespace std;

class RectangleMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, Mat& frame, vector<Rect>& faces) override {
        drawer.drawRectangles(frame, faces);
    }
    string getName() override {
        return "Rectangle";
    }
};
