cmake_minimum_required(VERSION 3.16)

project(Engine VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
	"src/Application.cpp"
	"src/Log.cpp"
)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME}
	PUBLIC 
		"."
		"vendor/spdlog/include"
)

target_precompile_headers(${PROJECT_NAME}
	PRIVATE
		<iostream>
		<memory>
		<utility>
		<algorithm>
		<functional>
		<string>
		<sstream>
		<array>
		<vector>
		<unordered_map>
		<unordered_set>
)

add_compile_definitions(ENGINE_BUILD_SHARED)
