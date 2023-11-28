#pragma once

#include "Entity.h"

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
	void draw(SDL_Renderer* renderer) override;
	void updateCollider(vec2 start, vec2 end) override;

private:

};

Wall::Wall() : Entity(0, 0)
{
	m_width = 1;
	m_height = 1;
	collider = new BoxCollider("wall", vec2((double)x, (double)y), vec2((double)x + m_width, (double)y + m_height));
	type = EntityType::WALL;
}

inline Wall::Wall(double x, double y, int width, int height) : Entity(x, y)
{
	m_width = width;
	m_height = height;
	collider = new BoxCollider("wall", vec2((double)x, (double)y), vec2((double)x + m_width, (double)y + m_height));
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

inline void Wall::draw(SDL_Renderer* renderer)
{
	SDL_FRect rectangle;

	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = m_width;
	rectangle.h = m_height;
	SDL_RenderFillRect(renderer, &rectangle);
}

inline void Wall::updateCollider(vec2 start, vec2 end)
{
	collider->update(start, end);
}
