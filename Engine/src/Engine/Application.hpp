#pragma once
#include "Core.h"

namespace Engine {

	class ENGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client app (Sandbox.cpp)
	Application* createApplication();
}
