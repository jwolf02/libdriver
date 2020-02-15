
set(SOURCES         HC_SR04.hpp
                    HC_SR04.cpp)

add_library(hcsr04 STATIC ${SOURCES})
target_include_directories(hcsr04 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GPIO_INCLUDE_DIR} ${GLOBAL_INCLUDE})
set_target_properties(hcsr04 PROPERTIES PUBLIC_HEADER "HC_SR04.hpp")
target_link_libraries(hcsr04 PUBLIC gpio)

install(TARGETS hcsr04 DESTINATION /usr/lib PUBLIC_HEADER DESTINATION /usr/include)

if (BUILD_EXAMPLES)
    add_executable(display_distance examples/display_distance.cpp)
    target_include_directories(display_distance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(display_distance PUBLIC hcsr04)
endif()