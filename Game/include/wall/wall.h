#pragma once

#include "entity\entity.h"

class Wall : public  Entity
{
	int m_width;
	int m_height;
public:
	Wall();
	Wall(double x, double y, int width, int height);
	~Wall();

	bool is_collided(BoxCollider* collider) override;
	BoxCollider* getCollider() override;

private:

};

Wall::Wall() : Entity(0, 0)
{
	m_width = 1;
	m_height = 1;
	collider = new BoxCollider("wall", Engine::Vector2f(x, y), Engine::Vector2f(x + m_width, y + m_height));
	type = EntityType::WALL;
}

inline Wall::Wall(double x, double y, int width, int height) : Entity(x, y)
{
	m_width = width;
	m_height = height;
	collider = new BoxCollider("wall", Engine::Vector2f(x, y), Engine::Vector2f(x + m_width, y + m_height));
	type = EntityType::WALL;
}

Wall::~Wall()
{
}

inline bool Wall::is_collided(BoxCollider* collider)
{
	return this->collider->is_collided(collider);
}

inline BoxCollider* Wall::getCollider()
{
	return collider;
}