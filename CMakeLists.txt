cmake_minimum_required (VERSION 2.8)

project(io)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(io io.cpp)

target_link_libraries(io ${OpenCV_LIBS})
