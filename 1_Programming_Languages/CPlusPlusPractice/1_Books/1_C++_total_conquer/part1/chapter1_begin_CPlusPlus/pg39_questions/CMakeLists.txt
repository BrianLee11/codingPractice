cmake_minimum_required(VERSION 3.30)
project(pg39_)

set(CMAKE_CXX_STANDARD 20)

add_executable(pg39_ main.cpp logic.cpp good_utility.cpp)

# Create static library (.lib on Windows, .a on Linux/macOS)
add_library(good_utility STATIC good_utility.cpp)