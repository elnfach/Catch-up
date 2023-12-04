#include "entity/entity.h"

Entity::Entity()
{
	type = EntityType::UNKNOWN;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
}

Entity::~Entity()
{
}
