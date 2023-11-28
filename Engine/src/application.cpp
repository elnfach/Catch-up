#include "application.h"
#include "window/window.h"

Engine::Application* Engine::Application::s_ptr_instance = nullptr;

Engine::Application::Application()
{
    if (s_ptr_instance)
    {
        __debugbreak();
    }
    s_ptr_instance = this;

    m_ptr_window = Window::create();
}

void Engine::Application::run()
{
    while (!m_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                m_running = SDL_TRUE;
                break;
            }
        }

        m_ptr_window->onUpdate();
        update();
    }
}
