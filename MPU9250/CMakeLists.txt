
set(SOURCES         MPU9250.hpp
                    MPU9250.cpp)

add_library(mpu9250 STATIC ${SOURCES})
target_include_directories(mpu9250 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLOBAL_INCLUDE})
target_link_libraries(mpu9250 PUBLIC rtimulib)
set_target_properties(mpu9250 PROPERTIES PUBLIC_HEADER "MPU9250.hpp")

install(TARGETS mpu9250 DESTINATION /usr/lib PUBLIC_HEADER_DESTINATION /usr/include)