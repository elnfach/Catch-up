#include "component.h"

Engine::Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = ComponentType::Unknown;
	/*game_object = new GameObject();
	transform = game_object->transform;*/
}

Engine::Component::Component(ComponentType type) : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = type;
	/*game_object = new GameObject();
	transform = game_object->transform;*/
}

Engine::Component::~Component()
{
}
