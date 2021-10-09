cmake_minimum_required(VERSION 3.20)
project(design-patterns)

set(CMAKE_CXX_STANDARD 17)

# Google test dependency
add_subdirectory(googletest)

set(CMAKE_CXX_CPPLINT "${PROJECT_SOURCE_DIR}/cpplint/cpplint.py")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

enable_testing()
add_subdirectory(creational)
