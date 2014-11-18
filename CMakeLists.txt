cmake_minimum_required(VERSION 2.8.4)
project(DeepNN)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
    header/header.h
    header/layer.h
    source/layer.cpp
    header/map.h
    source/map.cpp
)
add_executable(DeepNN ${SOURCE_FILES})