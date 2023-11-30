#ifndef CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H
#define CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H

#include <SDL_render.h>

#include "Catch-up/renderer/renderer_api.h"
#include <functional>

namespace Engine
{
	class Drawable;
	class SDL_RendererAPI : public RendererAPI
	{
#define SDL_MAX_UINT8   ((Uint8)0xFF)           /* 255 */
#define SDL_MIN_UINT8   ((Uint8)0x00)           /* 0 */
		typedef uint8_t Uint8;
		::SDL_Renderer* m_ptr_renderer = nullptr;
		bool vsync;
	private:
		void init(RendererProps& props);
		~SDL_RendererAPI();
	public:
		SDL_RendererAPI(RendererProps& props);
		void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
		void clear() override;
		void draw(Drawable* drawable) override;
		void present() override;

		virtual void shutdown() override;

		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override;
	};
}

#endif // !CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H