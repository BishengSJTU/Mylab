cmake_minimum_required(VERSION 3.13)
project(lab)

set(OpenCV_DIR  "/usr/local/share/OpenCV/")
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINATIONS})

set(CMAKE_CXX_STANDARD 14)

add_executable(lab main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(lab ${OpenCV_LIBS})