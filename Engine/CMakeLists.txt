cmake_minimum_required(VERSION 3.11)

project(Engine VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
	"src/Engine/Application.cpp"
	"src/Engine/Log.cpp"
)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME}
	PUBLIC "src"
	PUBLIC "vendor/spdlog/include"
)

add_compile_definitions(ENGINE_BUILD_SHARED)
