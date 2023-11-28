#include "sdl_renderer.h"

Engine::Renderer* Engine::Renderer::create(RendererProps props)
{
	return new SDL_Renderer(props);
}

void Engine::SDL_Renderer::init(RendererProps& props)
{
	m_ptr_renderer = SDL_CreateRenderer(props.window, props.api_name, props.flags);
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

void Engine::SDL_Renderer::draw()
{
	SDL_SetRenderDrawColor(m_ptr_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_ptr_renderer);
	SDL_RenderPresent(m_ptr_renderer);
}

void Engine::SDL_Renderer::setVSync(bool enabled)
{
	SDL_SetRenderVSync(m_ptr_renderer, enabled);
}
