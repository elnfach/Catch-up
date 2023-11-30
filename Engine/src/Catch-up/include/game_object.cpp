#include "object.h"
#include "game_object.h"
#include <SDL.h>

#include "components\drawable\rectangle_drawable.h"

Engine::GameObject::GameObject() : Object(ObjectType::GameObject)
{
	transform = new Transform();
	drawable = new RectangleDrawable(transform);
}

Engine::GameObject::~GameObject()
{

}