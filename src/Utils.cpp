#include "Utils/Utils.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;

void Utils::saveScreenshot(Mat frame) {
    time_t now = time(0);
    string timestamp = to_string(now);
    string filename = "screenshots/Screenshot_" + timestamp + ".jpg";
    imwrite(filename, frame);
    cout << "Screenshot saved: " << filename << endl;
}

void Utils::drawFPS(Mat& frame) {
    static int64 prev = getTickCount();

    int64 current = getTickCount();
    double fps = getTickFrequency() / (double)(current - prev);
    prev = current;

    string text = "FPS: " + to_string((int)fps);
    putText(frame,
        text,
        Point(20, 60),       
        FONT_HERSHEY_SIMPLEX,
        0.8,
        Scalar(255, 255, 0),
        2);
}
