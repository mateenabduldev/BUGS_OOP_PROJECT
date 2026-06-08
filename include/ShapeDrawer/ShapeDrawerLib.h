#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

// Abstract base (Abstraction)
class IShapeDrawer {
public:
    virtual void drawShape(cv::Mat& frame, std::vector<cv::Rect>& faces) = 0;
    virtual void drawFaceCount(cv::Mat& frame, int count) = 0;
    virtual std::string getShapeName() const = 0;
    virtual ~IShapeDrawer() {}
};

// (Inheritance)
class RectangleDrawer : public IShapeDrawer {

private:
    cv::Scalar color;

public:
    RectangleDrawer() {
        color = cv::Scalar(0, 255, 0);
    }

    void setColor(cv::Scalar newColor) {
        color = newColor;
    }

    void drawShape(cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        for (int i = 0; i < (int)faces.size(); i++) {
            cv::rectangle(frame, faces[i], color, 3);
        }
    }

    void drawFaceCount(cv::Mat& frame, int count) override {
        std::string text = "Faces: " + std::to_string(count) + " [Rectangle]";
        cv::putText(frame, text, cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 2);
    }

    std::string getShapeName() const override {
        return "Rectangle";
    }
};

class CircleDrawer : public IShapeDrawer {

private:
    cv::Scalar color;

public:
    CircleDrawer() {
        color = cv::Scalar(255, 0, 255);
    }

    void setColor(cv::Scalar newColor) {
        color = newColor;
    }

    void drawShape(cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        for (int i = 0; i < (int)faces.size(); i++) {
            cv::Point center(
                faces[i].x + faces[i].width / 2,
                faces[i].y + faces[i].height / 2);
            int radius = faces[i].width / 2;
            cv::circle(frame, center, radius, color, 3);
        }
    }

    void drawFaceCount(cv::Mat& frame, int count) override {
        std::string text = "Faces: " + std::to_string(count) + " [Circle]";
        cv::putText(frame, text, cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 2);
    }

    std::string getShapeName() const override {
        return "Circle";
    }
};

class EllipseDrawer : public IShapeDrawer {

private:
    cv::Scalar color;

public:
    EllipseDrawer() {
        color = cv::Scalar(0, 194, 225);
    }

    void setColor(cv::Scalar newColor) {
        color = newColor;
    }

    void drawShape(cv::Mat& frame, std::vector<cv::Rect>& faces) override {
        for (int i = 0; i < (int)faces.size(); i++) {
            cv::ellipse(frame,
                cv::Point(faces[i].x + faces[i].width / 2,
                    faces[i].y + faces[i].height / 2),
                cv::Size(faces[i].width / 2,
                    faces[i].height / 2),
                0, 0, 360, color, 3);
        }
    }

    void drawFaceCount(cv::Mat& frame, int count) override {
        std::string text = "Faces: " + std::to_string(count) + " [Ellipse]";
        cv::putText(frame, text, cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 2);
    }

    std::string getShapeName() const override {
        return "Ellipse";
    }
};
