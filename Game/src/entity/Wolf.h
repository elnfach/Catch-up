#pragma once
#include <time.h>

#include "Entity.h"
#include "RayCast.h"
#include <vector>
#include <functional>
#include "components\drawable\rectangle_drawable.h"

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
private:

};

Wolf::Wolf() : Entity(0, 0)
{
	m_width = 1;
	m_height = 1;
	type = EntityType::WOLF;
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	m_width = width;
	m_height = height;
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

inline void Wolf::move()
{
}

inline void Wolf::handleCollision(Entity& entity, std::function<void()> callback)
{
}