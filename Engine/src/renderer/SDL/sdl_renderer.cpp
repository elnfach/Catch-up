#include "sdl_renderer.h"

Renderer* Renderer::create(SDL_Window& window)
{
	return new SDL_Renderer(window);
}

void SDL_Renderer::init(SDL_Window& window)
{
	m_ptr_renderer = SDL_CreateRenderer(&window, NULL, SDL_RENDERER_SOFTWARE);
}

void SDL_Renderer::shutdown()
{
	SDL_DestroyRenderer(m_ptr_renderer);
}

SDL_Renderer::SDL_Renderer(SDL_Window& window)
{
	init(window);
}

SDL_Renderer::~SDL_Renderer()
{
	shutdown();
}
