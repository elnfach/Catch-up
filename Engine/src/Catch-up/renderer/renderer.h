#pragma once

#include <vector>
#include <functional>
#include "Catch-up\props.h"
#include "renderer_api.h"
#include "components\vector4f.h"

namespace Engine
{
	class Window;
	class Drawable;
	class Renderer
	{
		static RendererAPI* m_ptr_renderer_api;
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

		static void clear(const Vector4f color);
		static void drawRectangle(const Transform transform, Vector2f size, const Vector4f color);
		static void drawCircle();
		static void present();

		static void shutdown();

		static void OnWindowResize(unsigned int width, unsigned int height);
	};
}