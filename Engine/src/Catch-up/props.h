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
		void* window;
		const char* api_name;
		uint32_t flags;

		typedef enum
		{
			SDL_RENDERER_SOFTWARE = 0x00000001,         /**< The renderer is a software fallback */
			SDL_RENDERER_ACCELERATED = 0x00000002,      /**< The renderer uses hardware
															 acceleration */
			SDL_RENDERER_PRESENTVSYNC = 0x00000004      /**< Present is synchronized
															 with the refresh rate */
		} SDL_RendererFlags;

		RendererProps(void* window,
			const char* api_name = NULL,
			uint32_t flags = SDL_RENDERER_SOFTWARE
		) : window(window), api_name(api_name), flags(flags)
		{}
	};
}