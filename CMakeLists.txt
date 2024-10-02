set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME "tuiplusplus")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(PROJECT_VERSION "1.0-rel")
set(CMAKE_BUILD_TYPE Release)

cmake_minimum_required(VERSION 3.29)
project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC
    src/cmake.cpp
)

target_link_libraries(${PROJECT_NAME}
    ncurses
    ncursesw
)
