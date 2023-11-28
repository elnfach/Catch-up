#include "application.h"
#include "window/window.h"
#include "window/SDL/sdl_window.h"
#include "renderer/SDL/sdl_renderer.h"
#include <iostream>
#include "script_behaviour.h"

Engine::Application* Engine::Application::s_ptr_instance = nullptr;

Engine::ScriptBehaviour* Engine::ScriptBehaviour::create()
{
    return new ScriptBehaviour();
}

Engine::Application::Application()
{
    if (s_ptr_instance)
    {
        __debugbreak();
    }
    s_ptr_instance = this;

    m_ptr_window = Window::create();
    m_ptr_renderer = Renderer::create(RendererProps(m_ptr_window->getNativeWindow()));
    //m_ptr_script_behaviour= ScriptBehaviour::create();
    //m_ptr_script_behaviour->start();
    
}

Engine::Application::~Application()
{
    closeWindow();
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
        m_ptr_renderer->setColor(255, 255, 255, 255);
        m_ptr_renderer->clear();
        m_ptr_renderer->draw(draw());
        
        //m_ptr_script_behaviour->update();
        update();
    }
}

void Engine::Application::closeWindow()
{
    m_ptr_window->shutdown();
    m_ptr_renderer->shutdown();
    SDL_Quit();
}
