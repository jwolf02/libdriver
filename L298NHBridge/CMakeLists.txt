
set(SOURCES         L298NHBridge.hpp
                    L298NHBridge.cpp)

add_library(l298nhbridge STATIC ${SOURCES})
target_include_directories(l298nhbridge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} GLOBAL_INCLUDE)
target_link_libraries(l298nhbridge PUBLIC gpio)
set_target_properties(l298nhbridge PROPERTIES PUBLIC_HEADER "L298NHBridge.hpp")

install(TARGETS l298nhbridge DESTINATION /usr/lib PUBLIC_HEADER DESTINATION /usr/include)