#pragma once

#include "entity\entity.h"

class Wall : public  Entity
{
public:
	Wall();
	Wall(double x, double y, int width, int height);
	~Wall();

	void onCollisionEnter(GameObject game_object) override;
	EntityType getType() override;
private:
	Engine::BoxCollider* box_collider;
};