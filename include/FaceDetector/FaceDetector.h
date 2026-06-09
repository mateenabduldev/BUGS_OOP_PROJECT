#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <ctime>

using namespace cv;
using namespace std;

class FaceDetector {

private:
    CascadeClassifier faceCascade;
    double scaleFactor;
    int minNeighbors;
    int totalDetections;
    int maxFacesSeen;
    time_t sessionStart;

public:
    FaceDetector(string xmlPath);
    FaceDetector(string xmlPath, double scale, int minN);

    ~FaceDetector();

    vector<Rect> detectFaces(Mat frame);
    void drawFeatures(Mat& frame, vector<Rect>& faces);
    void printSummary();

    // ENCAPSULATION - Getters
    double getScaleFactor();
    int getMinNeighbors();

    // ENCAPSULATION - Setters
    void setScaleFactor(double scale);
    void setMinNeighbors(int minN);
};
