cmake_minimum_required(VERSION 3.10)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(${PROJECT_NAME} Sandbox.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
