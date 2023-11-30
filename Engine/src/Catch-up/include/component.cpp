#include "component.h"
#include "game_object.h"
#include "script_behaviour.h"
#include "component_base.h"

Engine::Component::Component() : Object(ObjectType::Component)
{
	name = "Default component name";
	component_type = ComponentType::Unknown;
	ComponentBase::addInstance(this);
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
	ComponentBase::addInstance(this);
}

Engine::Component::~Component()
{
}
