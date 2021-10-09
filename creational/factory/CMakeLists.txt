add_library(factory
        source/point_factory.cpp
        source/drink.cpp
        source/drink_factory.cpp)
target_include_directories(factory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_executable(factory_tests
        test/point_tests.cpp
        test/drink_factory_tests.cpp)
target_link_libraries(factory_tests factory gtest_main)
add_test(factory_tests factory_tests)