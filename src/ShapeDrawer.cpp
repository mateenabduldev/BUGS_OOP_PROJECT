#include "ShapeDrawer/ShapeDrawer.h"
using namespace cv;
using namespace std;

RectangleDrawer::RectangleDrawer() {
    color = Scalar(0, 255, 0);
}
void RectangleDrawer::setColor(Scalar newColor) {
    color = newColor;
}
void RectangleDrawer::drawShape(Mat& frame, vector<Rect>& faces) {
    for (int i = 0; i < (int)faces.size(); i++) {
        rectangle(frame, faces[i], color, 3);
    }
}
void RectangleDrawer::drawFaceCount(Mat& frame, int count) {
    string text = "Faces: " + to_string(count) + " [Rectangle]";
    putText(frame, text, Point(20, 40),
        FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255), 2);
}
string RectangleDrawer::getShapeName() const {
    return "Rectangle";
}

CircleDrawer::CircleDrawer() {
    color = Scalar(255, 0, 255);
}
void CircleDrawer::setColor(Scalar newColor) {
    color = newColor;
}
void CircleDrawer::drawShape(Mat& frame, vector<Rect>& faces) {
    for (int i = 0; i < (int)faces.size(); i++) {
        Point center(
            faces[i].x + faces[i].width / 2,
            faces[i].y + faces[i].height / 2);
        int radius = faces[i].width / 2;
        circle(frame, center, radius, color, 3);
    }
}
void CircleDrawer::drawFaceCount(Mat& frame, int count) {
    string text = "Faces: " + to_string(count) + " [Circle]";
    putText(frame, text, Point(20, 40),
        FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255), 2);
}
string CircleDrawer::getShapeName() const {
    return "Circle";
}

EllipseDrawer::EllipseDrawer() {
    color = Scalar(0, 194, 225);
}
void EllipseDrawer::setColor(Scalar newColor) {
    color = newColor;
}
void EllipseDrawer::drawShape(Mat& frame, vector<Rect>& faces) {
    for (int i = 0; i < (int)faces.size(); i++) {
        ellipse(frame,
            Point(faces[i].x + faces[i].width / 2,
                faces[i].y + faces[i].height / 2),
            Size(faces[i].width / 2,
                faces[i].height / 2),
            0, 0, 360, color, 3);
    }
}
void EllipseDrawer::drawFaceCount(Mat& frame, int count) {
    string text = "Faces: " + to_string(count) + " [Ellipse]";
    putText(frame, text, Point(20, 40),
        FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255), 2);
}
string EllipseDrawer::getShapeName() const {
    return "Ellipse";
}

void ShapeDrawer::drawRectangles(Mat& frame, vector<Rect>& faces) {
    rectDrawer.drawShape(frame, faces);
}
void ShapeDrawer::drawCircles(Mat& frame, vector<Rect>& faces) {
    circleDrawer.drawShape(frame, faces);
}
void ShapeDrawer::drawEllipses(Mat& frame, vector<Rect>& faces) {
    ellipseDrawer.drawShape(frame, faces);
}
void ShapeDrawer::drawFaceCount(Mat& frame, int count) {
    rectDrawer.drawFaceCount(frame, count);
}