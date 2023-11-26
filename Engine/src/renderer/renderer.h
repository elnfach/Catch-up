#pragma once
#include <SDL_render.h>

class Renderer
{
	SDL_Renderer* m_ptr_renderer = NULL;

	Renderer(SDL_Window& window);
public:
	Renderer() = delete;
	Renderer(const Renderer&) = delete;
	Renderer(const Renderer&&) = delete;
	void operator=(const Renderer&) = delete;

	void init(SDL_Window& window);

	static Renderer& get_instance();

	~Renderer();
};