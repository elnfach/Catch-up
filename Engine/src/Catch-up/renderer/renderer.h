#pragma once

#include <vector>
#include <functional>
#include "Catch-up\props.h"
#include "renderer_api.h"

namespace Engine
{
	class Window;
	class Drawable;
	class Renderer
	{
		static RendererAPI* m_ptr_renderer_api;
		static std::vector<Drawable*> m_drawable_list;
	protected:
		Renderer() {}
		virtual ~Renderer() {}
	public:
		Renderer(const Renderer&) = delete;
		Renderer(const Renderer&&) = delete;

		void operator=(const Renderer&) = delete;

		static void init(void* window);

		static Renderer* Instance()
		{
			static Renderer instance;
			return &instance;
		}
		static void shutdown();

		static void OnWindowResize(unsigned int width, unsigned int height);

		static void submit(Drawable* drawable);
		static void update();
	};
}