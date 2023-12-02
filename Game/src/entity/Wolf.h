#pragma once
#include <time.h>

#include "Entity.h"
#include "RayCast.h"
#include <vector>
#include <functional>
#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"

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
private:

};

Wolf::Wolf() : Entity(0, 0)
{
	type = EntityType::WOLF;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
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