#include "component.h"
#include "game_object.h"
#include "script_behaviour.h"

Engine::Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = ComponentType::Unknown;
}

Engine::Component::Component(ComponentType type) : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = type;
	if (type == ComponentType::ScriptBehaviour)
	{
		game_object = new GameObject();
		transform = game_object->transform;
	}
}

Engine::Component::~Component()
{
}
