#include "components/transform.h"

Engine::Transform::Transform() : Component(ComponentType::Transform)
{
	name = "Default transform name";
	position = Vector2f(0, 0);
}

Engine::Transform::~Transform()
{

}

void Engine::Transform::translate(Vector2f translation)
{
	position = translation;
}