cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)


add_executable(main4 src/main4.cpp inc/main4.hpp)
target_include_directories(main4 PUBLIC inc)
