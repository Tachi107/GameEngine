// -I/usr/lib/llvm-10/include/c++/v1
#include <Engine.hpp>
//#include <iostream>
//#include <array>

// My sandbox "extends" the engine
class Sandbox : public Engine::Application {
public:
	Sandbox() = default;

	~Sandbox() override = default;
};

// Entry point
Engine::Application* Engine::createApplication() {
	// On the heap because it's an entire application, will be very large (> 1MB (Windows) | > 8MB (Linux))
	return new Sandbox;
}
