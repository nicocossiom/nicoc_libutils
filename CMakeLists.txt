cmake_minimum_required(VERSION 3.0.0)
project(nicoc_libutils VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 99)
include(CTest)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(src/list src/map)
add_subdirectory(src test)