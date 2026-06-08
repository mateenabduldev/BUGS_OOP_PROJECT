#include "Application/Application.h"

using namespace cv;
using namespace std;

Application::Application()
    :
    camera(0),
    detector("data/models/haarcascade_frontalface_default.xml")
{
    currentMode = &rectangleMode;
    logger.log("Application Started");
}

void Application::processInput(char key) {
    if (key == '1') {
        currentMode = &rectangleMode;
        logger.log("Mode Changed To: Rectangle");
    }
    else if (key == '2') {
        currentMode = &circleMode;
        logger.log("Mode Changed To: Circle");
    }
    else if (key == '3') {
        currentMode = &ellipseMode;
        logger.log("Mode Changed To: Ellipse");
    }
    else if (key == 's' || key == 'S') {
        Utils::saveScreenshot(frame);
        logger.log("Screenshot Saved");
    }
}

void Application::run() {
    try {
        while (true) {
            if (!camera.readFrame(frame)) {
                throw runtime_error("Camera Frame Read Failed!");
            }
            flip(frame, frame, 1);
            vector<Rect> faces = detector.detectFaces(frame);
            detector.drawFeatures(frame, faces);
            currentMode->draw(drawer, frame, faces);
            drawer.drawFaceCount(frame, (int)faces.size());
            Utils::drawFPS(frame);
            putText(
                frame,
                "1=Rectangle  2=Circle  3=Ellipse  S=Screenshot",
                Point(10, 80),
                FONT_HERSHEY_SIMPLEX,
                0.6,
                Scalar(255, 255, 255),
                2
            );
            putText(
                frame,
                "Current Mode: " + currentMode->getName(),
                Point(10, 110),
                FONT_HERSHEY_SIMPLEX,
                0.7,
                Scalar(0, 255, 0),
                2
            );
            imshow("Smart Face Detection System", frame);
            logger.log("Faces Detected: ", (int)faces.size());
            char key = waitKey(1);
            processInput(key);
            if (key == 27)
                break;
        }
    }
    catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
        logger.log("Exception Occurred");
    }
}

Application::~Application() {
    logger.log("Application Closed");
    detector.printSummary();
}
