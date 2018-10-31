cmake_minimum_required(VERSION 3.9)
project(lab5Utpod)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab5Utpod UtPod_Driver.cpp song.h UtPod.h song.cpp UtPod_Driver.cpp UtPod.cpp)