if(EXISTS "/Users/pepperonico/code/nicoc_libutils/build/list_tests[1]_tests.cmake")
  include("/Users/pepperonico/code/nicoc_libutils/build/list_tests[1]_tests.cmake")
else()
  add_test(list_tests_NOT_BUILT list_tests_NOT_BUILT)
endif()
