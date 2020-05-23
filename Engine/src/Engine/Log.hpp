#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Engine {

	class ENGINE_API Log {
	public:
		static void init();
		//Class functions are automatically inlined
		[[nodiscard]] static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		[[nodiscard]] static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}  // namespace Engine

#ifndef NDEBUG
	// Core log macros
	#define ENGINE_CORE_TRACE(...)     ::Engine::Log::getCoreLogger()->trace(__VA_ARGS__)
	#define ENGINE_CORE_INFO(...)      ::Engine::Log::getCoreLogger()->info(__VA_ARGS__)
	#define ENGINE_CORE_WARN(...)      ::Engine::Log::getCoreLogger()->warn(__VA_ARGS__)
	#define ENGINE_CORE_ERROR(...)     ::Engine::Log::getCoreLogger()->error(__VA_ARGS__)
	#define ENGINE_CORE_CRITICAL(...)  ::Engine::Log::getCoreLogger()->critical(__VA_ARGS__)

	// Client log macros
	#define ENGINE_TRACE(...)          ::Engine::Log::getClientLogger()->trace(__VA_ARGS__)
	#define ENGINE_INFO(...)           ::Engine::Log::getClientLogger()->info(__VA_ARGS__)
	#define ENGINE_WARN(...)           ::Engine::Log::getClientLogger()->warn(__VA_ARGS__)
	#define ENGINE_ERROR(...)          ::Engine::Log::getClientLogger()->error(__VA_ARGS__)
	#define ENGINE_CRITICAL(...)       ::Engine::Log::getClientLogger()->critical(__VA_ARGS__)
#else
	// If in release, define log functions to nothing
	#define ENGINE_CORE_TRACE
	#define ENGINE_CORE_INFO
	#define ENGINE_CORE_WARN
	#define ENGINE_CORE_ERROR
	#define ENGINE_CORE_CRITICAL
	#define ENGINE_TRACE
	#define ENGINE_INFO
	#define ENGINE_WARN
	#define ENGINE_ERROR
	#define ENGINE_CRITICAL
#endif
