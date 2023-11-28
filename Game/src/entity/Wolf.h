#pragma once
#include <SDL3/SDL_render.h>
#include <time.h>

#include "Entity.h"
#include "RayCast.h"
#include <vector>
#include <functional>

class Wolf : public Entity
{
	int temp_x;
	int temp_y;
	int m_width;
	int m_height;

	

	RayCast* ray_cast = new RayCast();
public:
	Wolf();
	Wolf(double x, double y, int width, int height);
	~Wolf();

	bool is_collided(BoxCollider* collider) override;
	BoxCollider* getCollider() override;
	void draw(SDL_Renderer* renderer) override;
	void updateCollider(vec2 start, vec2 end) override;
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
	temp_x = 0;
	temp_y = 0;
	m_width = 1;
	m_height = 1;
	collider = new BoxCollider("wolf", vec2((double)x, (double)y), vec2((double)x + y + m_width, (double)y + m_height));
	type = EntityType::WOLF;
}

inline Wolf::Wolf(double x, double y, int width, int height) : Entity(x, y)
{
	temp_x = 0;
	temp_y = 0;
	m_width = width;
	m_height = height;
	collider = new BoxCollider("wolf", vec2((double)x, (double)y), vec2((double)x + m_width, (double)y + m_height));
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

inline bool Wolf::is_collided(BoxCollider* collider)
{
	return this->collider->is_collided(collider);
}

inline void Wolf::draw(SDL_Renderer* renderer)
{
	SDL_FRect rectangle;

	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = m_width;
	rectangle.h = m_height;

	SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
	SDL_RenderFillRect(renderer, &rectangle);
}

inline void Wolf::updateCollider(vec2 start, vec2 end)
{
	collider->update(start, end);
}

inline void Wolf::move()
{
	srand(time(0));
	std::vector<float> temp = ray_cast->cast();
	float degree = temp[rand() % temp.size()];
	if (vector)
	{
		x += (cos(degree) / 10) * (-1);
		y += (sin(degree) / 10) * (-1);
	}
	else {
		x += cos(degree) / 10;
		y += sin(degree) / 10;
	}
	updateCollider(vec2((double)x, (double)y), vec2((int)(x + m_width), (int)(y + m_height)));
}

inline void Wolf::handleCollision(Entity& entity, std::function<void()> callback)
{
	if (entity.getCollider()->is_collided(collider))
	{
		callback();
	}
}


inline BoxCollider* Wolf::getCollider()
{
	return collider;
}