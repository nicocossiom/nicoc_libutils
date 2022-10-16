cmake_minimum_required(VERSION 3.0.0)
project(nicoc_libutils VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
include(CTest)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Google tests
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include_directories(src/list)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
