#include "application.h"
#include "Catch-up/core/window.h"
#include "Platform/SDL/sdl_window.h"
#include "Platform/SDL/sdl_renderer_api.h"
#include "scene.h"
#include "script_behaviour.h"

#include <iostream>

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
    Renderer::init(m_ptr_window->getNativeWindow());
    m_ptr_scene = Scene::getInstance();
}

Engine::Application::~Application()
{
    Renderer::shutdown();
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
        m_ptr_scene->update();
        update();
    }
}

void Engine::Application::closeWindow()
{
    m_ptr_window->shutdown();
    SDL_Quit();
}
