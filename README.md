# BUGS_OOP_PROJECT
Object Oriented Programming Project; Live Webcam Face Detection Using OpenCV

A real-time face detection application built in C++ using OpenCV. The webcam feed is processed every frame to detect faces and overlay a shape around each one. The user can switch between rectangle, circle, and ellipse modes using the keyboard, save screenshots, and view live FPS and face count on screen.

Features:

Real-time face detection via Haar Cascade classifier
Three switchable drawing modes — rectangle, circle, ellipse
Live FPS counter and face count overlay
Colour-coded progress bar (green to red, scales with face count)
Screenshot saving with Unix timestamp filename
All events logged to logs/log.txt throughout the session
Session summary printed on exit — total detections, max faces, time elapsed

Requirements:

C++17 or later
OpenCV 4.x installed at D:/opencv/build (update path in CMakeLists.txt if different)
CMake 3.10 or later
Ninja build system
Visual Studio 2022 (MSVC)

Build Instructions:

Extract or clone the project folder
Open the folder in Visual Studio 2022 — it auto-detects CMakeLists.txt
If OpenCV is installed somewhere other than D:/opencv/build, update this line in CMakeLists.txt:

set(OpenCV_DIR "D:/opencv/build")

Select x64-Debug or x64-Release preset and build
Run MyOOPProject.exe from the build output directory

OOP Concepts Used:

Encapsulation — FaceDetector keeps scaleFactor, minNeighbors, totalDetections and maxFacesSeen private. They are only accessible through getters and setters with input validation.
Abstraction — ICameraSource defines a pure virtual interface for frame reading. Application never touches VideoCapture directly. IShapeDrawer hides all drawing details behind a clean interface.
Inheritance — CameraManager inherits ICameraSource. RectangleDrawer, CircleDrawer and EllipseDrawer all inherit IShapeDrawer. RectangleMode, CircleMode and EllipseMode all inherit Mode.
Polymorphism — Application holds a Mode* currentMode pointer. Calling currentMode->draw() dispatches to the correct override at runtime without any if-else chain.
Constructor Overloading — FaceDetector has two constructors. One accepts only the XML path and uses default values. The other accepts all three parameters explicitly.
Templates — Logger::log<T>() is a function template that accepts any type as the second argument — int, double, string all work with the same function.
Exception Handling — Application::run() wraps the entire loop in a try-catch block. CameraManager and FaceDetector throw std::runtime_error on construction failure.
File Handling — Logger appends every event to logs/log.txt using ofstream in ios::app mode. Utils::saveScreenshot() writes the current frame as a JPEG to the screenshots folder with a timestamp filename.
Static Members — Utils::saveScreenshot() and Utils::drawFPS() are static. No object needed, called directly as Utils::saveScreenshot(frame).
Destructors — Application::~Application() logs the closing event and calls detector.printSummary(). CameraManager::~CameraManager() releases the VideoCapture resource.
Exception Handling — Application::run() wraps the entire loop in a try-catch block. CameraManager and FaceDetector throw std::runtime_error on construction failure.
File Handling — Logger appends every event to logs/log.txt using ofstream in ios::app mode. Utils::saveScreenshot() writes the current frame as a JPEG to the screenshots folder with a timestamp filename.
Static Members — Utils::saveScreenshot() and Utils::drawFPS() are static. No object needed, called directly as Utils::saveScreenshot(frame).
Destructors — Application::~Application() logs the closing event and calls detector.printSummary(). CameraManager::~CameraManager() releases the VideoCapture resource.
