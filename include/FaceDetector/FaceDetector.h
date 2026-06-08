#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <ctime>

class FaceDetector {

private:
    cv::CascadeClassifier faceCascade;
    double scaleFactor;
    int minNeighbors;
    int totalDetections;
    int maxFacesSeen;
    time_t sessionStart;

public:
    // CONSTRUCTOR OVERLOADING
    FaceDetector(std::string xmlPath);
    FaceDetector(std::string xmlPath, double scale, int minN);

    ~FaceDetector();

    std::vector<cv::Rect> detectFaces(cv::Mat frame);
    void drawFeatures(cv::Mat& frame, std::vector<cv::Rect>& faces);
    void printSummary();

    // ENCAPSULATION - Getters
    double getScaleFactor();
    int getMinNeighbors();

    // ENCAPSULATION - Setters
    void setScaleFactor(double scale);
    void setMinNeighbors(int minN);
};
