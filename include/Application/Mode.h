#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "ShapeDrawer/ShapeDrawer.h"

using namespace cv;
using namespace std;

class Mode {
public:
    virtual void draw(ShapeDrawer& drawer, Mat& frame, vector<Rect>& faces) = 0;
    virtual string getName() = 0;
    virtual ~Mode() {}
};
