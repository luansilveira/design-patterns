cmake_minimum_required(VERSION 3.20)
project(design-patterns)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_CPPLINT "${PROJECT_SOURCE_DIR}/cpplint/cpplint.py")

add_subdirectory(googletest)
add_subdirectory(creational)
