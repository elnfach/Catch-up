#pragma once
#include <SDL.h>
#include <string>

#include "window_props.h"

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
	virtual void setVSync(bool enabled) = 0;
	virtual bool isVSync() const = 0;
	virtual void* getNativeWindow() const = 0;

	static Window* create(const WindowProps& props = WindowProps());
};