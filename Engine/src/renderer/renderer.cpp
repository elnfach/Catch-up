#include "renderer/renderer.h"

Renderer::Renderer(SDL_Window& window)
{
	init(window);
}

void Renderer::init(SDL_Window& window)
{
	m_ptr_renderer = SDL_CreateRenderer(&window, NULL, SDL_RENDERER_SOFTWARE);
}

Renderer& Renderer::get_instance()
{
	SDL_Window* window;
	static Renderer instance(*window);
	return instance;
}

Renderer::~Renderer()
{
}
