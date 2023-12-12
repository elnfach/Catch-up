#pragma once
#include <time.h>
#include <vector>
#include <functional>

#include "entity/entity.h"

#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"
#include "components\rigidbody\rigid_body.h"
#include "body.h"

class Wolf : public Entity
{
public:
	Wolf();
	Wolf(double x, double y, int width, int height);
	~Wolf();

	void move(Engine::Vector2f vec);
	void onCollisionEnter(GameObject game_object) override;

	EntityType getType() override;
private:
	Engine::RigidBody* rigid_body;
	Engine::BoxCollider* box_collider;

	EntityBody* body;
	bool vector = false;
};