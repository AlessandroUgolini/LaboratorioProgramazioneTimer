cmake_minimum_required(VERSION 3.19)
project(ProgettoTimerLaboratorio)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProgettoTimerLaboratorio main.cpp Timer.cpp Timer.h WDClock.cpp WDClock.h Subject.h Observer.h)