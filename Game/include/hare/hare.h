#pragma once

#include "entity\entity.h"

class Hare : Entity
{
public:
	Hare();
	Hare(double x, double y, int width, int height);
	~Hare();

	void move(Engine::Vector2f vec);
	void onCollisionEnter(GameObject game_object) override;

	EntityType getType() override;
private:
	Engine::BoxCollider* box_collider;
};