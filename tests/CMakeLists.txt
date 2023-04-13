set(TEST_SOURCES testRadixSortEngine.cpp ${PROJECT_SOURCE_DIR}/RadixSortEngine.cpp)

add_executable(
        testRadixSortEngine
        ${TEST_SOURCES})

target_include_directories(testRadixSortEngine PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        testRadixSortEngine
        gtest_main
        gtest
        pthread
)


include(GoogleTest)
gtest_discover_tests(testRadixSortEngine)
