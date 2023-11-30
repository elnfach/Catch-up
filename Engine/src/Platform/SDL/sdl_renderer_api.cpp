#include "Platform\SDL\sdl_renderer_api.h"
#include <components/drawable/drawable.h>
#include <iostream>
#include <functional>

void Engine::SDL_RendererAPI::init(RendererProps& props)
{
	m_ptr_renderer = SDL_CreateRenderer((::SDL_Window*)props.window, props.api_name, props.flags);
	if (m_ptr_renderer == nullptr)
	{
		__debugbreak();
	}
}

void Engine::SDL_RendererAPI::shutdown()
{
	SDL_DestroyRenderer(m_ptr_renderer);
}

Engine::SDL_RendererAPI::SDL_RendererAPI(RendererProps& props)
{
	init(props);
}

Engine::SDL_RendererAPI::~SDL_RendererAPI()
{
	shutdown();
}

void Engine::SDL_RendererAPI::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_ptr_renderer, r, g, b, a);
}

void Engine::SDL_RendererAPI::clear()
{
	SDL_RenderClear(m_ptr_renderer);
	SDL_RenderPresent(m_ptr_renderer);
}

void Engine::SDL_RendererAPI::draw(std::function<void(::SDL_Renderer* renderer)> fn)
{
	fn(m_ptr_renderer);
}

void Engine::SDL_RendererAPI::setVSync(bool enabled)
{
	SDL_SetRenderVSync(m_ptr_renderer, enabled);
	vsync = enabled;
}

bool Engine::SDL_RendererAPI::isVSync() const
{
	return vsync;
}
