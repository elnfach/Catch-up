#pragma once
#include "window/window.h"
#include "renderer/renderer.h"
#include <string>

namespace Engine
{
	class SDL_Window : public Window
	{
		::SDL_Window* m_ptr_window = nullptr;
		Renderer* m_ptr_renderer = nullptr;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vsync;
		};

		WindowData m_data;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

	public:
		SDL_Window(const WindowProps& props);
		virtual ~SDL_Window();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
		inline virtual void* getNativeWindow() const { return m_ptr_window; }
	};
}