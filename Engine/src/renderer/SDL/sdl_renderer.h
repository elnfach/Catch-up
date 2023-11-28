#ifndef CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H
#define CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H

#include <SDL_render.h>

#include "renderer/renderer.h"

namespace Engine
{
	class SDL_Renderer : public Renderer
	{
		::SDL_Renderer* m_ptr_renderer = nullptr;

		bool vsync;
	private:
		virtual void init(RendererProps& props);
	public:
		SDL_Renderer(RendererProps& props);
		~SDL_Renderer();

		void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
		void clear() override;
		void draw(Drawable* dr) override;

		virtual void shutdown() override;

		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override;
		inline void* getInstance() const override { return m_ptr_renderer; }
	};
}

#endif // !CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H