cmake_minimum_required(VERSION 3.20)
project(design-patterns)

set(CMAKE_CXX_STANDARD 20)

# Google test dependency
add_subdirectory(googletest)

set(CMAKE_CXX_CPPLINT "${PROJECT_SOURCE_DIR}/cpplint/cpplint.py")

enable_testing()
add_subdirectory(creational)
