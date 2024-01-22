add_library(infix STATIC src/infix.cpp)
target_include_directories(infix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(libstats PRIVATE libmath)
