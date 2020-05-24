cmake_minimum_required(VERSION 3.16)
project(GameEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")                               #-g3
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -stdlib=libc++ -Og -g3 -fuse-ld=lld")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
else()
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED true)
endif()

add_subdirectory(Engine)
add_subdirectory(Sandbox)

if(MSVC)
    set_target_properties(
        Engine Sandbox 
        PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded"
    )   #"MultiThreaded$<$<CONFIG:Debug>:Debug>"
endif(MSVC)
