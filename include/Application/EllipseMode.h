#pragma once
#include "Mode.h"

using namespace cv;
using namespace std;

class EllipseMode : public Mode {
public:
    void draw(ShapeDrawer& drawer, Mat& frame, vector<Rect>& faces) override {
        drawer.drawEllipses(frame, faces);
    }
    string getName() override {
        return "Ellipse";
    }
};
