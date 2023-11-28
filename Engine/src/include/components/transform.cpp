#include "components/transform.h"
#include <SDL.h>

Engine::Transform::Transform() : Component(ComponentType::Transform)
{
	name = "Default transform name";
}

Engine::Transform::~Transform()
{

}

void Engine::Transform::translate(Vector2f translation)
{

}