#include <SDL.h>

#include "Catch-up\renderer\renderer.h"
#include "components/drawable/drawable.h"
#include <iostream>


Engine::Drawable::Drawable() : Component(ComponentType::Drawable)
{
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = transform->position.x;
	rectangle->y = transform->position.y;
	rectangle->w = 25;
	rectangle->h = 25;

	if (rect == nullptr) delete rect;
	rect = rectangle;
}

Engine::Drawable::Drawable(Vector2f position, Vector2f end) : Component(ComponentType::Drawable)
{
	transform->position = position;
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = transform->position.x;
	rectangle->y = transform->position.y;
	rectangle->w = end.x;
	rectangle->h = end.y;

	if(rect == nullptr) delete rect;
	rect = rectangle;
}

Engine::Drawable::Drawable(Transform* transform) : Component(ComponentType::Drawable)
{
	this->transform = transform;
	::SDL_FRect* rectangle = new ::SDL_FRect();

	rectangle->x = this->transform->position.x;
	rectangle->y = this->transform->position.y;
	rectangle->w = 25;
	rectangle->h = 25;

	if (rect == nullptr) delete rect;
	rect = rectangle;
}

Engine::Drawable::~Drawable()
{
	delete rect;
	delete transform;
}

void Engine::Drawable::update()
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