cmake_minimum_required(VERSION 3.19)

project(test)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(TEST_SOURCE_FILES runAllTests.cpp ClockFormatTest.cpp StopwatchTest.cpp TimerTest.cpp)
add_executable(runAppTests ${TEST_SOURCE_FILES})
target_link_libraries(runAppTests gtest gtest_main core ${wxWidgets_LIBRARIES})