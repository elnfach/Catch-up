#include "application.h"
#include "Catch-up/core/window.h"
#include "Platform/SDL/sdl_window.h"
#include "Platform/SDL/sdl_renderer_api.h"
#include "scene.h"
#include "Catch-up\utils\platform_utils.h"
#include "time_step.h"
#include "script_behaviour.h"
#include "Catch-up/scripting/script_engine.h"

#include <iostream>

Engine::Application* Engine::Application::s_ptr_instance = nullptr;

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
    m_ptr_scene->start();

    lua.init();
    lua.open("main.lua");
    lua.start();
    
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

        float time = Engine::Time::getTime();
        Timestep::getInstance()->setDeltaTime(time - m_last_frame_time);
        m_last_frame_time = time;
        m_ptr_window->update();
        lua.update(Timestep::getDeltaTime());
        m_ptr_scene->update();
    }
}

void Engine::Application::closeWindow()
{
    m_ptr_window->shutdown();
    SDL_Quit();
}
