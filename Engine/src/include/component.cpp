#include "component.h"

Engine::Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
}

Engine::Component::Component(ObjectType type) : Object(type)
{
	name = "Default component name";
}

Engine::Component::~Component()
{
}
