cmake_minimum_required(VERSION 3.0)

project(libdriver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD      11)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -O2 -Wall -mtune=native -march=native")

set(GLOBAL_INCLUDE          ${CMAKE_CURRENT_SOURCE_DIR}/util)

option(BUILD_ALL "build all targets" OFF)
option(BUILD_TIMER "build timer library" OFF)
option(BUILD_I2C "build I2C wrapper" OFF)
option(GPIO_BACKEND_WIRINGPI "build GPIO library with wiringPi backend" OFF)
option(BUILD_GPIO "build GPIO library (necessary for some other targets" OFF)
option(BUILD_L298NHBRIDGE "build L298N H-Bridge wrapper" OFF)
option(BUILD_GPS "build GPS library" OFF)
option(BUILD_HCSR04 "build HC-SR04 wrapper" OFF)
option(BUILD_MPU9250 "build MPU9250 wrapper" OFF)
option(BUILD_COMPLETE_LIB "build one single library" OFF)
option(BUILD_EXAMPLES "build library and wrapper examples" OFF)
option(BUILD_TESTS "build test cases" ON)

option(BUILD_STATIC_LIBS "build all libraries as static" ON)
option(BUILD_SHARED_LIBS "build all libraries as shared" OFF)

if (BUILD_ALL)
    set(BUILD_TIMER ON)
    set(BUILD_I2C ON)
    set(BUILD_GPIO ON)
    set(BUILD_L298NHBRIDGE ON)
    set(BUILD_GPS ON)
    set(BUILD_HCSR04 ON)
endif()

if (BUILD_STATIC_LIBS)
    message("-- building libraries as static")
    set(LIB_TYPE STATIC)
elseif(BUILD_SHARED_LIBS)
    message("-- building libraries as shared")
    set(LIB_TYPE SHARED)
else()
    message(FATAL_ERROR "library type has to be specified")
endif()

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

if (BUILD_MPU9250)
    add_subdirectory(MPU9250)
endif()
