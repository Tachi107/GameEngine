cmake_minimum_required(VERSION 3.11)
project(Sandbox)

add_executable(${PROJECT_NAME} "src/Sandbox.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
