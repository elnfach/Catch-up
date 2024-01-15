#include "entity/entity.h"

#include <corecrt_math_defines.h>

Game::Entity::Entity()
{
	type = EntityType::UNKNOWN;
	transform = &getComponent<Engine::Transform>();
	drawable = &getComponent<Engine::RectangleDrawable>();
}

Game::Entity::~Entity()
{
	delete transform;
	delete drawable;
}

Engine::Vector2f Game::Entity::calcDirection(Engine::Vector3f rotation)
{
	float angle_in_radians = rotation.z * M_PI / 180.0f;
	float cos_angle = cos(angle_in_radians);
	float sin_angle = sin(angle_in_radians);

	Engine::Vector2f direction = Engine::Vector2f(cos_angle, sin_angle);

	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0.0f) {
		direction.x /= length;
		direction.y /= length;
	}

	return direction;
}

float Game::Entity::calcDirectionAngle(Engine::Vector2f direction)
{
	float angle = std::atan2(direction.y, direction.x);
	float degrees = angle * 180.0 / M_PI;
	return degrees;
}
