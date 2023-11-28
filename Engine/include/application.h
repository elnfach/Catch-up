#pragma once

#include <vector>

struct SDL_Renderer;
namespace Engine
{
    typedef unsigned int SDL_bool;
    class Window;
    class Application
    {
        Window* m_ptr_window;

        SDL_bool m_running = false;
        //std::vector<Object*> objects;
        static Application* s_ptr_instance;

    public:
        Application();
        virtual ~Application() {}

        void run();

        virtual void update() {}

        inline Window& getWindow() { return *m_ptr_window; }

        inline static Application& getInstance() { return *s_ptr_instance; }
    };

    Application* createApplication();
}