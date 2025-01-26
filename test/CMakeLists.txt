cmake_minimum_required(VERSION 3.5)

project(test-home-dir LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} "main.cpp" "../src/home-dir.h" "../src/home-dir.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE "../src")
