#ifndef CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H
#define CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H

#include <SDL_render.h>

#include "renderer/renderer.h"

namespace Engine
{
	class SDL_Renderer : public Renderer
	{
		::SDL_Renderer* m_ptr_renderer = nullptr;
	private:
		virtual void init(RendererProps& props);
		virtual void shutdown();
	public:
		SDL_Renderer(RendererProps& props);
		~SDL_Renderer();

		void draw() override;
		virtual void setVSync(bool enabled) override;
		inline virtual void* getInstance() const { return m_ptr_renderer; }
	};
}

#endif // !CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H