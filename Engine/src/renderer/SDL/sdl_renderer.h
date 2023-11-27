#ifndef CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H
#define CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H

#include "renderer/renderer.h"

class SDL_Renderer : public Renderer
{
	SDL_Renderer* m_ptr_renderer = nullptr;
private:

	virtual void init(SDL_Window& window);
	virtual void shutdown();
public:
	SDL_Renderer(SDL_Window& window);
	~SDL_Renderer();

	void setColor() override;
	void drawLine() override;
	void drawLines() override;
	void drawPoint() override;
	void drawPoints() override;
	void drawRectangle() override;
	void drawRectangles() override;
	void drawTexture() override;

	virtual Renderer& getInstance() const { return *m_ptr_renderer; }
};

#endif // !CATCH_UP_ENGINE_SRC_RENDERER_SDL_SDL_RENDERER_H