cmake_minimum_required(VERSION 3.5)
project(FDCM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Where to find CMake modules and OpenCV

set(OpenCV_DIR "/usr/local/share/OpenCV/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(FDCM main.cpp IprovedFDCM.h IprovedFDCM.cpp)
# add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_videoio    )
# linking
target_link_libraries(FDCM ${OpenCV_LIBS} /usr/local/lib/libyaml-cpp.a)