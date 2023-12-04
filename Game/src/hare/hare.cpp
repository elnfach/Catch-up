#include "hare/hare.h"
#include <components/rigidbody/rigid_body.h>

Hare::Hare() : Entity()
{
	name = "hare";
	type = EntityType::HARE;

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>();
}

Hare::Hare(double x, double y, int width, int height)
{
	name = "hare";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::HARE;
}

Hare::~Hare()
{
}

void Hare::move(Engine::Vector2f vec)
{
}

void Hare::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wolf")
	{
		destroy(this);
	}
}

EntityType Hare::getType()
{
	return type;
}
