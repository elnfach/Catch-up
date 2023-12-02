#include "component.h"
#include "script_behaviour.h"
#include "scene.h"

Engine::Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = ComponentType::Unknown;
}

Engine::Component::Component(ComponentType type) : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = type;
}

Engine::Component::~Component()
{
}
