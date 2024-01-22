add_library(vm STATIC src/virtual_machine.cpp)
target_include_directories(vm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vm PUBLIC common loaders)

add_executable(
    vm_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(vm_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(vm_tests)

add_test(NAME vm_tests COMMAND vm_tests)
