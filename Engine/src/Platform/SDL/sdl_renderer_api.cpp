#include <iostream>
#include <functional>

#include "Platform\SDL\sdl_renderer_api.h"

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

void Engine::SDL_RendererAPI::setColor(const Vector4f color)
{
	SDL_SetRenderDrawColor(m_ptr_renderer, color.x, color.y, color.z, color.w);
}

void Engine::SDL_RendererAPI::clear()
{
	SDL_RenderClear(m_ptr_renderer);
}

void Engine::SDL_RendererAPI::drawRectangle(const Transform transform, Vector2f size, const Vector4f color)
{
	::SDL_FRect rect{};
	rect.x = transform.position.x;
	rect.y = transform.position.y;
	rect.w = size.x;
	rect.h = size.y;
	SDL_SetRenderDrawColor(m_ptr_renderer, color.x, color.y, color.z, color.w);
	SDL_RenderFillRect(m_ptr_renderer, &rect);
}

void Engine::SDL_RendererAPI::present()
{
	SDL_RenderPresent(m_ptr_renderer);
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
