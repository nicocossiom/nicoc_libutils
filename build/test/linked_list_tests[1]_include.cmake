if(EXISTS "/Users/pepperonico/code/nicoc_libutils/build/test/linked_list_tests[1]_tests.cmake")
  include("/Users/pepperonico/code/nicoc_libutils/build/test/linked_list_tests[1]_tests.cmake")
else()
  add_test(linked_list_tests_NOT_BUILT linked_list_tests_NOT_BUILT)
endif()