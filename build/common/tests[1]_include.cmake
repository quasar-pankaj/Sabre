if(EXISTS "/home/pankaj/Projects/CPP/sabre/build/common/tests[1]_tests.cmake")
  include("/home/pankaj/Projects/CPP/sabre/build/common/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()