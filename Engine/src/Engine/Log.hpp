#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Engine {

	class ENGINE_API Log {
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}