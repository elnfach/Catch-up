#include "components/transform.h"

Engine::Transform::Transform() : Component(ComponentType::Transform)
{
	name = "Default transform name";
	position = Vector2f(0.0f, 0.0f);
	rotation = Vector2f(0.0f, 0.0f);
	scale = Vector2f(1.0f, 1.0f);
}

Engine::Transform::~Transform()
{

}

void Engine::Transform::translate(Vector2f translation)
{
	position = translation;
}