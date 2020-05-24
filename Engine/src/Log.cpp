#include "Log.hpp"

namespace Engine {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");			// Timestamp, logger name, message, color
		coreLogger = spdlog::stdout_color_mt("ENGINE");	//Creating a multi-threader colored stdout console
		coreLogger->set_level(spdlog::level::trace);
		ENGINE_CORE_WARN("Initialized core logger");
		
		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
		ENGINE_INFO("C++ version: {0}", __cplusplus);
	}

}  // namespace Engine
