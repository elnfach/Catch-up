#pragma once
#include <time.h>

#include "entity/entity.h"
#include "utils/RayCast.h"
#include <vector>
#include <functional>
#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"
#include "components\rigidbody\rigid_body.h"

class Wolf : public Entity
{
public:
	Wolf();
	Wolf(double x, double y, int width, int height);
	~Wolf();

	void move(float x, float y);

	void handleCollision(Entity& entity, std::function<void()> callback);

	EntityType getType() override
	{
		return type;
	}

	Engine::Transform* transform;
	Engine::RectangleDrawable* drawable;
	Engine::RigidBody* rigid_body;
	Engine::BoxCollider* box_collider;
private:

};

Wolf::Wolf() : Entity(0, 0)
{
	type = EntityType::WOLF;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
	rigid_body = &getComponent<Engine::RigidBody>();
	box_collider = &getComponent<Engine::BoxCollider>();
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
	rigid_body = &getComponent<Engine::RigidBody>();
	box_collider = &getComponent<Engine::BoxCollider>();
	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

inline void Wolf::move(float x, float y)
{
	transform->position.x = x;
	transform->position.y = y;
}

inline void Wolf::handleCollision(Entity& entity, std::function<void()> callback)
{
}