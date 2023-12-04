#include "wall/wall.h"

Wall::Wall() : Entity()
{
	name = "wall";
	type = EntityType::WALL;

	box_collider = &addComponent<Engine::BoxCollider>();
}

Wall::Wall(double x, double y, int width, int height) : Entity()
{
	name = "wall";

	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::WOLF;
}

Wall::~Wall()
{
}

void Wall::onCollisionEnter(GameObject game_object)
{
	std::cout << name << " collided with " << game_object.getName() << std::endl;
}

EntityType Wall::getType()
{
	return type;
}
