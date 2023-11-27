#include "application.h"
#include "window/window.h"

Application* Application::s_ptr_instance = nullptr;

Application::Application()
{
    if (s_ptr_instance)
    {
        __debugbreak();
    }
    s_ptr_instance = this;

    m_ptr_window = Window::create();
}

void Application::run()
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
