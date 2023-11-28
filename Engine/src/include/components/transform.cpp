#include "components/transform.h"

Engine::Transform::Transform() : Component(ObjectType::Transform)
{
	name = "Default transform name";
}

Engine::Transform::~Transform()
{

}
