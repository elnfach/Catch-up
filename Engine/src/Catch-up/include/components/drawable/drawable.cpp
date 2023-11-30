#include <SDL.h>

#include "components/drawable/drawable.h"


Engine::Drawable::Drawable()
{
	transform = new Transform();
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = 1280/ 2 - 25;
	rectangle->y = 720 / 2 - 25;
	rectangle->w = 25;
	rectangle->h = 25;
	
	rect = rectangle;
}

Engine::Drawable::Drawable(Vector2f position, Vector2f end)
{
	transform->position = position;
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = transform->position.x;
	rectangle->y = transform->position.y;
	rectangle->w = end.x;
	rectangle->h = end.y;

	rect = rectangle;
}

Engine::Drawable::Drawable(Transform* transform)
{
	this->transform = transform;
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = this->transform->position.x;
	rectangle->y = this->transform->position.y;
	rectangle->w = 25;
	rectangle->h = 25;

	rect = rectangle;
}

Engine::Drawable::~Drawable()
{
}

//void Engine::Drawable::update()
//{
//	::SDL_FRect* rectangle = new ::SDL_FRect();
//
//	rectangle->x = transform->position.x;
//	rectangle->y = transform->position.y;
//	rectangle->w = 25;
//	rectangle->h = 25;
//
//	rect = rectangle;
//}