#include "Application.hpp"
#include "Events/Event.hpp"	//TODO: Questo non dovrei poterlo fare
#include "Engine/Events/ApplicationEvent.hpp"
#include "Engine/Log.hpp"

namespace Engine {
	
	Application::Application() = default;
	Application::~Application() = default;

	void Application::run() {
		WindowResizeEvent event(1920, 1080);
		if (event.isInCategory(EventCategory::application)) { ENGINE_TRACE(event); }
		if (event.isInCategory(EventCategory::input)) { ENGINE_ERROR(event); }
		while (true);
	}
} // namespace Engine
