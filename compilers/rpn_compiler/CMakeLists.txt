add_library(rpn_compiler STATIC src/rpn.cpp)
target_include_directories(rpn_compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(libstats PRIVATE libmath)
