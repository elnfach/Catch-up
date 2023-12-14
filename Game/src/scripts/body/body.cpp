#include "body.h"

Game::EntityBody::EntityBody()
{
	type = EntityType::BODY;
}

Game::EntityBody::EntityBody(Engine::Vector2f start_position, Engine::Vector2f head_size) : Entity()
{
	drawable->size = head_size * 1.5;
	transform->position = start_position - head_size * 1.5;
	transform->position.x = head_size.x * 1.5;

	type = EntityType::BODY;
}

Game::EntityBody::~EntityBody()
{
}

Game::EntityType Game::EntityBody::getType()
{
	return type;
}
