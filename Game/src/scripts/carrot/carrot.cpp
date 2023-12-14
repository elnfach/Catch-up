#include "carrot/carrot.h"
#include "event/event_manager.h"

Game::Carrot::Carrot() : Entity()
{
	name = "carrot";
	type = EntityType::CARROT;

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>();
}

Game::Carrot::Carrot(double x, double y, int width, int height) : Entity()
{
	name = "carrot";

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;
	drawable->color = Engine::Vector4f(255.0f, 166.0f, 0.0f, 0.0f);

	type = EntityType::CARROT;
}

Game::Carrot::~Carrot()
{
}

void Game::Carrot::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() != "wall")
	{
		EventManager::getInstance()->destroy(this->GetUUID());
	}
}

Game::EntityType Game::Carrot::getType()
{
	return type;
}
