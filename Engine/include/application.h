#pragma once

#include <vector>

namespace Engine
{
    typedef unsigned int SDL_bool;

    class Scene;
    class Window;
    class Application
    {
        Window* m_ptr_window;
        Scene* m_ptr_scene;

        SDL_bool m_running = false;
        
        float m_LastFrameTime = 0.0f;
        static Application* s_ptr_instance;

    public:
        Application();
        virtual ~Application();

        void run();

        void closeWindow();

        inline Window& getWindow() { return *m_ptr_window; }

        inline static Application& getInstance() { return *s_ptr_instance; }
    };

    Application* createApplication();
}