cmake_minimum_required(VERSION 3.5)
project(LSD)

set(OpenCV_DIR  "/usr/local/share/OpenCV/")
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINATIONS})


add_executable(LSD main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)

target_link_libraries(LSD ${OpenCV_LIBS})
