
set(SOURCES         GPS.hpp
                    GPS.cpp
                    gps_data.hpp
                    nmea.hpp
                    nmea.cpp
                    serial.hpp
                    serial.cpp)

add_library(gps STATIC ${SOURCES})
target_include_directories(gps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} GLOBAL_INCLUDE)
target_link_libraries(gps PUBLIC m pthread)
set_target_properties(gps PROPERTIES PUBLIC_HEADER "GPS.hpp;gps_data.hpp")

install(TARGETS gps DESTINATION /usr/lib PUBLIC_HEADER DESTINATION /usr/include)

if (BUILD_EXAMPLES)
    add_executable(position_logger examples/position_logger.cpp)
    target_include_directories(position_logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(position_logger gps)

    add_executable(compute_uncertainity examples/compute_uncertainity.cpp)
    target_include_directories(compute_uncertainity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(compute_uncertainity PUBLIC gps)
endif()

if (BUILD_TESTS)
    add_executable(nmea_test test/nmea_test.cpp)
    target_include_directories(nmea_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLOBAL_INCLUDE})
    target_link_libraries(nmea_test gps)

    add_executable(gps_test test/gps_test.cpp)
    target_include_directories(gps_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLOBAL_INCLUDE})
    target_link_libraries(gps_test gps)

    add_test(NAME NMEA COMMAND nmea_test)
    add_test(NAME GPS COMMAND gps_test)
endif()
