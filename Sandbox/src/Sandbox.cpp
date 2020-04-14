#include <Engine.hpp>

// My sandbox "extends" the engine
class Sandbox : public Engine::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

// Entry point
Engine::Application* Engine::createApplication() {
	// On the heap because it's an entire application, will be very large (> 1MB (Windows) | > 8MB (Linux))
	return new Sandbox;
}
