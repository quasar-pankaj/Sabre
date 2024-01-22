add_subdirectory(infix_compiler)
add_subdirectory(rpn_compiler)

#add_library(compilers STATIC stats.cpp)
#target_include_directories(compilers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(compilers PRIVATE libmath)
