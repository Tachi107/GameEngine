cmake_minimum_required(VERSION 3.16)
project(Sandbox)

add_executable(${PROJECT_NAME} "src/Sandbox.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
