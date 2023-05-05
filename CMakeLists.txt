cmake_minimum_required(VERSION 3.18.4)
project(vc_v4l2_opencv_test)

set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_PREFIX_PATH "/usr/lib64/cmake/")
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_LIST_DIR}/include ${OpenCV_INCLUDE_DIRS})

find_package(OpenCV 4.7.0 REQUIRED)

add_executable(vc_v4l2_opencv_test main.cpp)
target_link_libraries(vc_v4l2_opencv_test ${OpenCV_LIBS})
