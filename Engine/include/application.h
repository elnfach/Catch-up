#pragma once

#include <vector>

struct SDL_Renderer;
namespace Engine
{
    typedef unsigned int SDL_bool;

    class Window;
    class Drawable;
    class Renderer;
    class ScriptBehaviour;
    class ComponentBase;
    class Application
    {
        Window* m_ptr_window;
        Renderer* m_ptr_renderer;
        ComponentBase* m_ptr_component_base;

        SDL_bool m_running = false;
        
        static Application* s_ptr_instance;

    public:
        Application();
        virtual ~Application();

        void run();

        virtual void update() = 0;
        virtual Drawable* draw() = 0;

        void closeWindow();

        inline Window& getWindow() { return *m_ptr_window; }

        inline static Application& getInstance() { return *s_ptr_instance; }
    };

    Application* createApplication();
}