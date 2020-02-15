
set(SOURCES             gpio.hpp
                        gpio.cpp
                        sys_gpio.hpp
                        sys_gpio.cpp)

set(GPIO_INCLUDE_DIR    ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library(gpio STATIC ${SOURCES})
target_include_directories(gpio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} GLOBAL_INCLUDE)
set_target_properties(gpio PROPERTIES PUBLIC_HEADER "gpio.hpp")
if (GPIO_BACKEND_WIRINGPI)
    target_link_libraries(gpio PUBLIC wiringpi pthread)
endif()

install(TARGETS gpio DESTINATION /usr/lib PUBLIC_HEADER DESTINATION /usr/include)