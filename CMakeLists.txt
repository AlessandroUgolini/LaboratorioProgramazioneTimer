cmake_minimum_required(VERSION 3.19)
project(ProgettoTimerLaboratorio)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_subdirectory(test)

set(SOURCE_FILES Clock.cpp Clock.h Timer.cpp Timer.h cApp.h cMain.cpp cMain.h clockFrame.cpp clockFrame.h timerFrame.cpp timerFrame.h stopwatchFrame.cpp stopwatchFrame.h Stopwatch.cpp Stopwatch.h)

add_executable(Timer cApp.cpp)
add_library(core ${SOURCE_FILES})

target_link_libraries(Timer ${wxWidgets_LIBRARIES} core)

