cmake_minimum_required(VERSION 3.12)
project(TLG)

set(OpenCV_DIR  "/usr/local/share/OpenCV/")
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINATIONS})

add_definitions(-std=c++11)

add_executable(TLG main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(TLG ${OpenCV_LIBS} /usr/local/lib/libyaml-cpp.a)