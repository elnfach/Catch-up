#include "sdl_window.h"
#include <iostream>

void Engine::SDL_Window::init(const WindowProps& props)
{
	m_data.title = props.title;
	m_data.width = props.width;
	m_data.height = props.height;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		int success = SDL_Init(SDL_INIT_VIDEO);
		std::cout << "SDL_INIT ERROR!";
		__debugbreak();
	}

	m_ptr_window = SDL_CreateWindow(m_data.title.c_str(), m_data.width, m_data.height, NULL);
}

void Engine::SDL_Window::shutdown()
{
	SDL_DestroyWindow(m_ptr_window);
}

Engine::Window* Engine::Window::create(const WindowProps& props)
{
	return new SDL_Window(props);
}

Engine::SDL_Window::SDL_Window(const WindowProps& props)
{
	init(props);
}

Engine::SDL_Window::~SDL_Window()
{
	shutdown();
}

void Engine::SDL_Window::update()
{

}
