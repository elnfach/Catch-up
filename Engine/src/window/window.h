#pragma once
#include <SDL.h>
#include <string>

#include "props.h"

namespace Engine
{
	class Window
	{
	public:
		Window() {}
		Window(const Window&) = delete;
		Window(const Window&&) = delete;
		virtual ~Window() {}

		void operator=(const Window&) = delete;

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual void* getNativeWindow() const = 0;
		virtual void shutdown() = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};
}