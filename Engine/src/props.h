#pragma once
#include <string>

namespace Engine
{
	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;
		WindowProps(std::string title = "Catch up!",
			unsigned int width = 1280,
			unsigned int height = 720
		) : title(title), width(width), height(height)
		{}
	};

	struct RendererProps
	{
		::SDL_Window* window;
		const char* api_name;
		Uint32 flags;

		RendererProps(::SDL_Window* window,
			const char* api_name = NULL,
			Uint32 flags = SDL_RENDERER_SOFTWARE
		) : window(window), api_name(api_name), flags(flags)
		{}
	};
}