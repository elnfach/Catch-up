#include "Platform\SDL\sdl_renderer_api.h"
#include "renderer_api.h"

Engine::RendererAPI::API Engine::RendererAPI::s_API = Engine::RendererAPI::API::SDL;

Engine::RendererAPI* Engine::RendererAPI::create(RendererProps props)
{
	switch (s_API)
	{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::SDL:		return new SDL_RendererAPI(props);
	}

	return nullptr;
}
