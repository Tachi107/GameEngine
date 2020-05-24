#pragma once

// So, in my client app, I need to create a createApplication() function that returns an Engine::Application pointer (to the heap)

extern Engine::Application* Engine::createApplication();

#ifdef _WIN64
	int main(int argc, char** argv) {
		Engine::Application* application = Engine::createApplication();
		application->run();
		delete application;
	}
#elif defined (__GNUC__)
	int main(int argc, char** argv) {
		Engine::Log::init();
		Engine::Application* application = Engine::createApplication();
		application->run();
		// Once run() terminates, the memory gets freed
		delete application;
	}
#endif
