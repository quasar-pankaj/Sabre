add_library(loaders 
    STATIC 
    src/byte_code_loader.cpp 
    src/lexer.cpp 
    src/tokenizer.cpp 
    src/scanner.cpp
)

target_include_directories(loaders PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(loaders PUBLIC common)

add_executable(
    loader_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(loader_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(loader_tests)

add_test(NAME loader_tests COMMAND loader_tests)
