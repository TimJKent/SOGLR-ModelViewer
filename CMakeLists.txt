cmake_minimum_required(VERSION 3.11)
project(SOGLR-ModelViewer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(SOGLR)
include_directories(SOGLR/include)



add_executable(SOGLR-ModelViewer src/main.cpp)
target_link_libraries(SOGLR-ModelViewer PRIVATE SOGLR)

file(GLOB_RECURSE SOGLR_MV_SOURCES src/*.cpp src/*.c)