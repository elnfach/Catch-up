#include "entity/entity.h"

Entity::Entity() : Engine::ScriptBehaviour()
{
	type = EntityType::UNKNOWN;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
}

Entity::~Entity()
{
}
