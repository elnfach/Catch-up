#include "object.h"
#include "game_object.h"
#include <SDL.h>

Engine::GameObject::GameObject() : Object(ObjectType::GameObject)
{
	drawable = new Drawable(transform);
	transform = new Transform();
}

Engine::GameObject::~GameObject()
{

}