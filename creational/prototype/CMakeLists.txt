add_library(prototype
        source/prototype.cpp)
target_include_directories(prototype PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_executable(prototype_tests
        test/prototype_tests.cpp)
target_link_libraries(prototype_tests prototype gtest_main)
add_test(prototype_tests prototype_tests)