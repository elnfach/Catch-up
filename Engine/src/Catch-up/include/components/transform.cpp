#include "components/transform.h"

Engine::Transform::Transform() : Component(ComponentType::Transform)
{
	name = "Default transform name";
	position = Vector2f(0, 0);
	locale_position = position;
}

Engine::Transform::~Transform()
{

}

void Engine::Transform::translate(Vector2f translation)
{

}