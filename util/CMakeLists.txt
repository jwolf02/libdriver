
set(GLOBAL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_executable(util_test test/common_test.cpp common.hpp)
target_include_directories(util_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME COMMON COMMAND util_test)