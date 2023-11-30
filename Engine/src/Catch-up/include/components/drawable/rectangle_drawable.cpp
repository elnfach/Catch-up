#include <SDL.h>

#include "Catch-up\renderer\renderer.h"
#include "components\drawable\rectangle_drawable.h"
#include <iostream>

Engine::RectangleDrawable::RectangleDrawable() : Drawable()
{
	Renderer::submit(this);
}

Engine::RectangleDrawable::RectangleDrawable(Vector2f position, Vector2f end) : Drawable(position, end)
{
	Renderer::submit(this);
}

Engine::RectangleDrawable::RectangleDrawable(Transform* transform) : Drawable(transform)
{
	Renderer::submit(this);
}

Engine::RectangleDrawable::~RectangleDrawable()
{
}

Engine::Drawable* Engine::RectangleDrawable::draw()
{
	rect->x = this->transform->position.x;
	rect->y = this->transform->position.y;
	return this;
}
