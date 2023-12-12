#pragma once

#include "components/rigidbody/rigid_body.h"
#include "entity\entity.h"

class Hare : public Entity
{
public:
	Hare();
	Hare(double x, double y, int width, int height);
	~Hare();

	void move(Engine::Vector2f vec);
	void onCollisionEnter(GameObject game_object) override;

	EntityType getType() override;
private:
	Engine::RigidBody* rigid_body;
	Engine::BoxCollider* box_collider;
};