add_executable(
    linked_list_tests
    list_tests.cc
)
target_link_libraries(
    linked_list_tests
    GTest::gtest_main
    linked_list
)

include(GoogleTest)
gtest_discover_tests(linked_list_tests)
