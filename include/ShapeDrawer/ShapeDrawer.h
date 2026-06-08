#pragma once
#include "ShapeDrawerLib.h"

// ShapeDrawer is the facade used by Application
// It holds the three concrete drawers and delegates based on active shape
class ShapeDrawer {
private:
    RectangleDrawer rectDrawer;
    CircleDrawer circleDrawer;
    EllipseDrawer ellipseDrawer;

public:
    void drawRectangles(cv::Mat& frame, std::vector<cv::Rect>& faces) {
        rectDrawer.drawShape(frame, faces);
    }

    void drawCircles(cv::Mat& frame, std::vector<cv::Rect>& faces) {
        circleDrawer.drawShape(frame, faces);
    }

    void drawEllipses(cv::Mat& frame, std::vector<cv::Rect>& faces) {
        ellipseDrawer.drawShape(frame, faces);
    }

    void drawFaceCount(cv::Mat& frame, int count) {
        rectDrawer.drawFaceCount(frame, count);
    }
};
