#include "sdl_renderer.h"
#include <components/drawable.h>
#include <iostream>

Engine::Renderer* Engine::Renderer::create(RendererProps props)
{
	return new SDL_Renderer(props);
}

void Engine::SDL_Renderer::init(RendererProps& props)
{
	m_ptr_renderer = SDL_CreateRenderer((::SDL_Window*)props.window, props.api_name, props.flags);
}

void Engine::SDL_Renderer::shutdown()
{
	SDL_DestroyRenderer(m_ptr_renderer);
}

Engine::SDL_Renderer::SDL_Renderer(RendererProps& props)
{
	init(props);
}

Engine::SDL_Renderer::~SDL_Renderer()
{
	shutdown();
}

void Engine::SDL_Renderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_ptr_renderer, r, g, b, a);
}

void Engine::SDL_Renderer::clear()
{
	SDL_RenderClear(m_ptr_renderer);
}

void Engine::SDL_Renderer::draw(Drawable* dr)
{
	setColor(0, 0, 0, 0);
	SDL_RenderFillRect(m_ptr_renderer, dr->rect);
	SDL_RenderPresent(m_ptr_renderer);
}

void Engine::SDL_Renderer::setVSync(bool enabled)
{
	SDL_SetRenderVSync(m_ptr_renderer, enabled);
	vsync = enabled;
}

bool Engine::SDL_Renderer::isVSync() const
{
	return vsync;
}
