#include <SDL.h>

#include "Catch-up\renderer\renderer.h"
#include "components\drawable\rectangle_drawable.h"
#include <iostream>

Engine::RectangleDrawable::RectangleDrawable() : Component(ComponentType::RectangleDrawable)
{
	color = Vector4f(255, 255, 255, 255);
	size = Vector2f(25, 25);
}

Engine::RectangleDrawable::~RectangleDrawable()
{
}
