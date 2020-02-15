
set(SOURCES                 I2CDev.hpp
                            I2CDev.cpp)

add_library(i2c STATIC ${SOURCES})
target_include_directories(i2c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLOBAL_INCLUDE})
set_target_properties(i2c PROPERTIES PUBLIC_HEADER "I2CDev.hpp")

install(TARGETS i2c DESTINATION /usr/lib PUBLIC_HEADER DESTINATION /usr/include)