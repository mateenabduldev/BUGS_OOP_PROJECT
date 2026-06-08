#include "FaceDetector/FaceDetector.h"
#include <iostream>

using namespace cv;
using namespace std;

// OVERLOADING
FaceDetector::FaceDetector(string xmlPath) {
    scaleFactor = 1.1;
    minNeighbors = 4;
    totalDetections = 0;
    maxFacesSeen = 0;
    sessionStart = time(0);

    if (!faceCascade.load(xmlPath)) {
        throw runtime_error("XML file load failed: " + xmlPath);
    }
}

FaceDetector::FaceDetector(string xmlPath, double scale, int minN) {
    scaleFactor = scale;
    minNeighbors = minN;
    totalDetections = 0;
    maxFacesSeen = 0;
    sessionStart = time(0);

    if (!faceCascade.load(xmlPath)) {
        throw runtime_error("XML file load failed: " + xmlPath);
    }
}

FaceDetector::~FaceDetector() {
    // printSummary is now called explicitly from Application destructor
}

// faces detector
vector<Rect> FaceDetector::detectFaces(Mat frame) {
    vector<Rect> faces;
    Mat gray;

    cvtColor(frame, gray, COLOR_BGR2GRAY);

    faceCascade.detectMultiScale(gray,
        faces,
        scaleFactor,
        minNeighbors);

    // update stats
    int count = (int)faces.size();
    totalDetections += count;
    if (count > maxFacesSeen)
        maxFacesSeen = count;

    return faces;
}

// progress bar + stats overlay
void FaceDetector::drawFeatures(Mat& frame, vector<Rect>& faces) {
    int count = (int)faces.size();

    int red = (255 * min(count, 10)) / 10;
    int green = 255 - red;
    Scalar color(0, green, red);

    // progress bar
    int barW = 200;
    int filled = (min(count, 10) * barW) / 10;

    rectangle(frame, Rect(10, 110, barW, 18), Scalar(80, 80, 80), -1);
    if (filled > 0)
        rectangle(frame, Rect(10, 110, filled, 18), color, -1);
    rectangle(frame, Rect(10, 110, barW, 18), Scalar(200, 200, 200), 1);

    putText(frame, "Faces: " + to_string(count) + "/10",
        Point(218, 124), FONT_HERSHEY_SIMPLEX, 0.5, color, 1);
}

// session summary
void FaceDetector::printSummary() {
    int seconds = (int)difftime(time(0), sessionStart);

    cout << "\n======= Session Summary =======" << endl;
    cout << "Total Time      : " << seconds / 60 << " min " << seconds % 60 << " sec" << endl;
    cout << "Total Detections: " << totalDetections << endl;
    cout << "Max Faces Seen  : " << maxFacesSeen << endl;
    cout << "================================\n" << endl;
}

// GETTERS
double FaceDetector::getScaleFactor() {
    return scaleFactor;
}

int FaceDetector::getMinNeighbors() {
    return minNeighbors;
}

// SETTERS
void FaceDetector::setScaleFactor(double scale) {
    if (scale > 1.0) {
        scaleFactor = scale;
    }
}

void FaceDetector::setMinNeighbors(int minN) {
    if (minN > 0) {
        minNeighbors = minN;
    }
}
