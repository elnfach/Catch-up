#include "object.h"
#include "game_object.h"
#include <SDL.h>

Engine::GameObject::GameObject() : Object(ObjectType::GameObject)
{
	transform = new Transform();
	drawable = new Drawable(transform);
}

Engine::GameObject::~GameObject()
{

}