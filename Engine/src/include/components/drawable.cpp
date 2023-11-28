#include <SDL.h>

#include "components/drawable.h"


Engine::Drawable::Drawable()
{
	transform = new Transform();
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = 100;
	rectangle->y = 100;
	rectangle->w = 25;
	rectangle->h = 25;
	
	rect = rectangle;
}

Engine::Drawable::Drawable(Transform* transform) 
{
	this->transform = transform;
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = 100;
	rectangle->y = 100;
	rectangle->w = 25;
	rectangle->h = 25;

	rect = rectangle;
}

Engine::Drawable::~Drawable()
{
}
