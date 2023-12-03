#pragma once
#include <time.h>
#include <vector>
#include <functional>

#include "entity/entity.h"
#include "utils/RayCast.h"

#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"
#include "components\rigidbody\rigid_body.h"

class Wolf : public Entity
{
public:
	Wolf();
	Wolf(double x, double y, int width, int height);
	~Wolf();

	void move(Engine::Vector2f vec);
	void onCollisionEnter(GameObject* game_object) override;

	EntityType getType() override
	{
		return type;
	}

	Engine::Transform* transform;
	Engine::RectangleDrawable* drawable;
	Engine::RigidBody* rigid_body;
	Engine::BoxCollider* box_collider;
private:
	bool vector = false;
};

Wolf::Wolf() : Entity(0, 0)
{
	name = "wolf";
	type = EntityType::WOLF;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>();
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	name = "wolf";
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();

	rigid_body = &addComponent<Engine::RigidBody>();
	box_collider = &addComponent<Engine::BoxCollider>();

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

inline void Wolf::move(Engine::Vector2f vec)
{
	if (vector)
	{
		transform->position = transform->position + (vec * (-1));
		return;
	}
	transform->position = transform->position + vec;
}

inline void Wolf::onCollisionEnter(GameObject* game_object)
{
	std::cout << game_object->getName() << std::endl;
	vector = true;
}