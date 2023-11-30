#pragma once
#include "Catch-up/core/window.h"
#include "Catch-up/renderer/renderer.h"
#include <string>

namespace Engine
{
	class SDL_Window : public Window
	{
		::SDL_Window* m_ptr_window = nullptr;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
		};

		WindowData m_data;

	private:
		virtual void init(const WindowProps& props);

	public:
		SDL_Window(const WindowProps& props);
		virtual ~SDL_Window();

		void onUpdate() override;

		virtual void shutdown() override;

		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }
		inline virtual void* getNativeWindow() const { return m_ptr_window; }
	};
}