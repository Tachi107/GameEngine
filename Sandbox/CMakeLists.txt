cmake_minimum_required(VERSION 3.10)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g3 -fuse-ld=lld")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
endif()

add_executable(${PROJECT_NAME} "src/Sandbox.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
