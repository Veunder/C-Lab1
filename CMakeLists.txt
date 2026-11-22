cmake_minimum_required(VERSION 3.16)

project(ML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV 4 REQUIRED)

add_executable(ML main.cpp)

target_link_libraries(ML PRIVATE ${OpenCV_LIBS})

target_include_directories(ML PRIVATE ${OpenCV_INCLUDE_DIRS})