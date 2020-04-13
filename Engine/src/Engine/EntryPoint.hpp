#pragma once

extern Engine::Application* Engine::createApplication();

#ifdef _WIN32
    int main(int argc, char** argv) {
        auto application = Engine::createApplication();
        application->run();
        delete application;
    }
#elif defined (__GNUC__)
    int main(int argc, char** argv) {
        auto application = Engine::createApplication();
        application->run();
        delete application;
    }
#endif
