cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)


add_executable(main2 src/main2.cpp inc/main2.hpp)
target_include_directories(main2 PUBLIC inc)

