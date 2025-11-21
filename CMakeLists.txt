cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(figures
    main.cpp
    point.h point.cpp
    figure.h
    triangle.h triangle.cpp
    square.h square.cpp
    rectangle.h rectangle.cpp
    array.h array.cpp
    factory.h
)
