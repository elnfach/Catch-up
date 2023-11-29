#pragma once
#include <time.h>

#include "Entity.h"
#include "RayCast.h"
#include <vector>
#include <functional>
#include "components/drawable.h"

class Wolf : public Entity
{
	int m_width;
	int m_height;

	
public:
	Wolf();
	Wolf(double x, double y, int width, int height);
	~Wolf();

	void move();

	void handleCollision(Entity& entity, std::function<void()> callback);

	EntityType getType() override
	{
		return type;
	}

	bool vector = false;

	Engine::Drawable* drawable;
private:

};

Wolf::Wolf() : Entity(0, 0)
{
	m_width = 1;
	m_height = 1;
	collider = new BoxCollider("wolf", Engine::Vector2f(transform->position.x, transform->position.y), Engine::Vector2f(transform->position.x + m_width, transform->position.y + m_height));
	drawable = new Engine::Drawable();
	type = EntityType::WOLF;
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	m_width = width;
	m_height = height;
	drawable = new Engine::Drawable();
	collider = new BoxCollider("wolf", Engine::Vector2f(x, y), Engine::Vector2f(x + m_width, y + m_height));
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

inline void Wolf::move()
{
	transform->position.x = 100;
	transform->position.y = 100;
}

inline void Wolf::handleCollision(Entity& entity, std::function<void()> callback)
{
}