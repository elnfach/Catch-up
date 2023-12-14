#include "Platform\SDL\sdl_renderer_api.h"
#include <iostream>

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
	float xOffset = size.x / 2;
	float yOffset = size.y / 2;
	SDL_Point rectangle[4] = { 
		{transform.position.x - xOffset, transform.position.y - yOffset},
		{transform.position.x + xOffset, transform.position.y - yOffset},
		{transform.position.x + xOffset, transform.position.y + yOffset},
		{transform.position.x - xOffset, transform.position.y + yOffset} 
	};

	float centerX = (rectangle[0].x + rectangle[1].x + rectangle[2].x + rectangle[3].x) / 4;
	float centerY = (rectangle[0].y + rectangle[1].y + rectangle[2].y + rectangle[3].y) / 4;

	for (int i = 0; i < 4; ++i) {
		rectangle[i].x -= centerX;
		rectangle[i].y -= centerY;
	}

	float angle = transform.rotation.z * SDL_PI_F / 180.0f;

	for (int i = 0; i < 4; ++i) {
		float x = rectangle[i].x;
		float y = rectangle[i].y;
		rectangle[i].x = x * cos(angle) - y * sin(angle);
		rectangle[i].y = x * sin(angle) + y * cos(angle);
	}

	for (int i = 0; i < 4; ++i) {
		rectangle[i].x += centerX;
		rectangle[i].y += centerY;
	}

	SDL_SetRenderDrawColor(m_ptr_renderer, color.x, color.y, color.z, color.w);

	for (int i = 0; i < 4; ++i) {
		SDL_RenderLine(m_ptr_renderer, rectangle[i].x, rectangle[i].y, rectangle[(i + 1) % 4].x, rectangle[(i + 1) % 4].y);
	}
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
