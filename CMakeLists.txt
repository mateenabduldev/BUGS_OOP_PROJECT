cmake_minimum_required(VERSION 3.10)

project(MyOOPProject)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR "D:/opencv/build")

find_package(OpenCV REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

add_library(CameraManager
    src/CameraManager.cpp
)

target_include_directories(
    CameraManager
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    CameraManager
    PUBLIC
    ${OpenCV_LIBS}
)

add_library(FaceDetector
    src/FaceDetector.cpp
)

target_include_directories(
    FaceDetector
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    FaceDetector
    PUBLIC
    ${OpenCV_LIBS}
)

add_library(ShapeDrawer
    src/ShapeDrawer.cpp
)

target_include_directories(
    ShapeDrawer
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ShapeDrawer
    PUBLIC
    ${OpenCV_LIBS}
)

add_library(Utils
    src/Utils.cpp
)

target_include_directories(
    Utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    Utils
    PUBLIC
    ${OpenCV_LIBS}
)

add_library(Application
    src/Application.cpp
)

target_include_directories(
    Application
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    Application
    PUBLIC
    CameraManager
    FaceDetector
    ShapeDrawer
    Utils
    ${OpenCV_LIBS}
)

add_executable(MyOOPProject
    app/main.cpp
)

target_link_libraries(
    MyOOPProject
    PRIVATE
    Application
)

target_compile_definitions(MyOOPProject PRIVATE
    PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
)
