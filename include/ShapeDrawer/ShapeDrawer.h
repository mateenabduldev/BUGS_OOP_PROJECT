#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

class IShapeDrawer {
public:
    virtual void drawShape(Mat& frame, vector<Rect>& faces) = 0;
    virtual void drawFaceCount(Mat& frame, int count) = 0;
    virtual string getShapeName() const = 0;
    virtual ~IShapeDrawer() {}
};

class RectangleDrawer : public IShapeDrawer {
private:
    Scalar color;
public:
    RectangleDrawer();
    void setColor(Scalar newColor);
    void drawShape(Mat& frame, vector<Rect>& faces) override;
    void drawFaceCount(Mat& frame, int count) override;
    string getShapeName() const override;
};
//.
class CircleDrawer : public IShapeDrawer {
private:
    Scalar color;
public:
    CircleDrawer();
    void setColor(Scalar newColor);
    void drawShape(Mat& frame, vector<Rect>& faces) override;
    void drawFaceCount(Mat& frame, int count) override;
    string getShapeName() const override;
};

class EllipseDrawer : public IShapeDrawer {
private:
    Scalar color;
public:
    EllipseDrawer();
    void setColor(Scalar newColor);
    void drawShape(Mat& frame, vector<Rect>& faces) override;
    void drawFaceCount(Mat& frame, int count) override;
    string getShapeName() const override;
};

class ShapeDrawer {
private:
    RectangleDrawer rectDrawer;
    CircleDrawer circleDrawer;
    EllipseDrawer ellipseDrawer;
public:
    void drawRectangles(Mat& frame, vector<Rect>& faces);
    void drawCircles(Mat& frame, vector<Rect>& faces);
    void drawEllipses(Mat& frame, vector<Rect>& faces);
    void drawFaceCount(Mat& frame, int count);
};
