add_library(builder)

target_sources(builder
        PRIVATE source/builder.cpp
                source/fluent_builder.cpp
                source/groovy_style_builder.cpp
                source/person_builder.cpp)

target_include_directories(builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_executable(builder_tests
        test/builder_tests.cpp
        test/fluent_builder_tests.cpp
        test/groovy_style_builder_tests.cpp
        test/person_builder_tests.cpp)
target_link_libraries(builder_tests builder gtest_main)
add_test(builder_tests builder_tests)