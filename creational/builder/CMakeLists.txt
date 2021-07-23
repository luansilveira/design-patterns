add_library(builder source/builder.cpp)
target_include_directories(builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_executable(builder_tests test/builder_tests.cpp)
target_link_libraries(builder_tests builder gtest_main)
add_test(builder_tests builder_tests)