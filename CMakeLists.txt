cmake_minimum_required(VERSION 3.0)

project(libdriver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD      11)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -O2 -Wall -mtune=native -march=native")

set(GLOBAL_INCLUDE          ${CMAKE_CURRENT_SOURCE_DIR}/util)

option(BUILD_TIMER "build timer library" ON)
option(BUILD_I2C "build I2C wrapper" ON)
option(GPIO_BACKEND_WIRINGPI "build GPIO library with wiringPi backend" OFF)
option(BUILD_GPIO "build GPIO library (necessary for some other targets" ON)
option(BUILD_L298NHBRIDGE "build L298N H-Bridge wrapper" ON)
option(BUILD_GPS "build GPS library" ON)
option(BUILD_HCSR04 "build HC-SR04 wrapper" ON)
option(BUILD_EXAMPLES "build library and wrapper examples" OFF)

enable_testing()

add_subdirectory(util)

if (BUILD_TIMER)
    add_subdirectory(timer)
endif()

if (BUILD_I2C)
    add_subdirectory(I2C)
endif()

if (BUILD_GPIO)
    add_subdirectory(gpio)
endif()

if (BUILD_L298NHBRIDGE)
    add_subdirectory(L298NHBridge)
endif()

if (BUILD_GPS)
    add_subdirectory(gps)
endif()

if (BUILD_HCSR04)
    add_subdirectory(HC_SR04)
endif()