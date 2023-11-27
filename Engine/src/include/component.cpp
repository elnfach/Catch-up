#include "component.h"

Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
}

Component::Component(ObjectType type) : Object(type)
{
	name = "Default component name";
}

Component::~Component()
{
}
