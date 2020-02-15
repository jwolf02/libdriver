
set(TIMER_SOURCES       Timer.hpp
                        Timer.cpp)

set(Timer_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR})

set(Timer_LIB           timer)

add_library(timer STATIC ${TIMER_SOURCES})
target_include_directories(timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(timer PUBLIC rt)

install(TARGETS timer DESTINATION /usr/lib)

add_executable(timer_test test/timer_test.cpp)
target_include_directories(timer_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLOBAL_INCLUDE})
target_link_libraries(timer_test PUBLIC timer rt)

add_test(NAME Timer COMMAND timer_test)