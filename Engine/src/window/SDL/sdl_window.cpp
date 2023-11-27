#include "sdl_window.h"
#include <iostream>

void SDL_Window::init(const WindowProps& props)
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

void SDL_Window::shutdown()
{
	SDL_DestroyWindow(m_ptr_window);
	SDL_Quit();
}

Window* Window::create(const WindowProps& props)
{
	return new SDL_Window(props);
}

SDL_Window::SDL_Window(const WindowProps& props)
{
	init(props);
}

SDL_Window::~SDL_Window()
{
	shutdown();
}

void SDL_Window::onUpdate()
{
	SDL_SetRenderDrawColor(m_ptr_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_ptr_renderer);
	SDL_RenderPresent(m_ptr_renderer);
}

void SDL_Window::setVSync(bool enabled)
{
	SDL_SetRenderVSync(m_ptr_renderer, enabled);

	m_data.vsync = enabled;
}

bool SDL_Window::isVSync() const
{
	return m_data.vsync;
}
