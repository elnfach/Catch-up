#pragma once
#include <SDL_render.h>

class Renderer
{
protected:
	Renderer() {}
public:
	Renderer(const Renderer&) = delete;
	Renderer(const Renderer&&) = delete;
	virtual ~Renderer();
	void operator=(const Renderer&) = delete;

	virtual void setColor() = 0;

	virtual void drawLine() = 0;
	virtual void drawLines() = 0;
	virtual void drawPoint() = 0;
	virtual void drawPoints() = 0;
	virtual void drawRectangle() = 0;
	virtual void drawRectangles() = 0;
	virtual void drawTexture() = 0;

	virtual Renderer& getInstance() const = 0;

	static Renderer* create(SDL_Window& window);
};