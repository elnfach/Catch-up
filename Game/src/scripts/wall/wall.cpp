#include "wall/wall.h"

Game::Wall::Wall() : Entity()
{
	name = "wall";
	type = EntityType::WALL;

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>();
}

Game::Wall::Wall(double x, double y, int width, int height) : Entity()
{
	name = "wall";

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::WALL;
}

Game::Wall::~Wall()
{
}

void Game::Wall::onCollisionEnter(GameObject game_object)
{
	
}

EntityType Game::Wall::getType()
{
	return type;
}
