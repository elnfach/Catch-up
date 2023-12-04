#include "wolf/wolf.h"

Wolf::Wolf() : Entity()
{
	name = "wolf";
	type = EntityType::WOLF;

	box_collider = &addComponent<Engine::BoxCollider>();
}

Wolf::Wolf(double x, double y, int width, int height) : Entity()
{
	name = "wolf";

	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

void Wolf::move(Engine::Vector2f vec)
{
	if (vector)
	{
		transform->position = transform->position + (vec * (-1));
		return;
	}
	transform->position = transform->position + vec;
}

void Wolf::onCollisionEnter(GameObject game_object)
{
	std::cout << name << " collided with " << game_object.getName() << std::endl;
	vector = (vector) ? false : true;
}

EntityType Wolf::getType()
{
	return type;
}
