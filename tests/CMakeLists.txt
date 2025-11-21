# Download and setup Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fdab60b31b4c6b6fd5f8d3.zip
)

FetchContent_MakeAvailable(googletest)

# Single test executable
add_executable(test_all test_all.cpp)

# Link with gtest
target_link_libraries(test_all gtest_main)

# Include directories
target_include_directories(test_all PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add test
add_test(NAME AllTests COMMAND test_all)
