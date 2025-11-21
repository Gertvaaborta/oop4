include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fdab60b31b4c6b6fd5f8d3.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(test_all test_all.cpp)
target_link_libraries(test_all gtest_main)
target_include_directories(test_all PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME AllTests COMMAND test_all)
