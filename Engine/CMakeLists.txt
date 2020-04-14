cmake_minimum_required(VERSION 3.10)

project(Engine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(${PROJECT_NAME} SHARED "src/Engine/Application.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME} PUBLIC "src" PUBLIC "${PROJECT_SOURCE_DIR}/vendor/spdlog/include")

add_compile_definitions(ENGINE_BUILD_SHARED)
