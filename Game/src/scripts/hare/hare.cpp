#include "catch_up.h"
#include "event/event_manager.h"
#include "hare/hare.h"
#include "time_step.h"
#include <corecrt_math_defines.h>
#include <random.h>

void Game::Hare::isAngry(Engine::Vector2f direction)
{
	Engine::Vector2f b;
	for (auto& i : Game::EventManager::getInstance()->getWolfTeam())
	{
		if (m_visibility_range >= Engine::Vector2f(i - transform->position).magnitude())
		{
			b = Engine::Vector2f(i - transform->position).normalized();						// wolf
		}
	}

	float angle = acos(direction.x * b.x + direction.y * b.y) * 180.0f * M_PI;

	transform->position += b * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
	transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(b));
}

Game::Hare::Hare() : Entity()
{
	name = "hare";
	type = EntityType::HARE;

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>();
}

Game::Hare::Hare(double x, double y, int width, int height)
{
	name = "hare";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	type = EntityType::HARE;
}

Game::Hare::Hare(double x, double y, int width, int height, std::vector<Engine::Vector2f> map)
{
	name = "hare";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	m_map = map;
	type = EntityType::HARE;
}

Game::Hare::~Hare()
{
	delete rigid_body;
	delete box_collider;
}

void Game::Hare::start()
{
}

void Game::Hare::update()
{
	Engine::Vector2f direction = calcDirection(transform->rotation);
	Engine::Vector2f dir = Engine::Vector2f(direction.x, direction.y).normalized();
	Engine::Vector2f b;
	for (auto& i : Game::EventManager::getInstance()->getCarrots())
	{
		if (m_visibility_range >= Engine::Vector2f(i - transform->position).magnitude())
		{
			b = Engine::Vector2f(i - transform->position).normalized();						// carrot
		}
	}

	float angle = acos(dir.x * b.x + dir.y * b.y) * 180.0f * M_PI;

	float min = FLT_MAX;
	Engine::Vector2f point;
	float temp_point;
	for (auto& i : m_map)
	{
		temp_point = Engine::Vector2f(i - transform->position).magnitude();
		if (min > temp_point && m_visibility_range >= temp_point)
		{
			min = temp_point;
			point = Engine::Vector2f(i - transform->position).normalized();
		}
	}

	m_velocity = point * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
	if (m_is_angry)
	{
		isAngry(dir);
	}
	else
	{
		if (m_angle / 2 > angle)
		{
			transform->position += b * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
			transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(b));
		}
		else {
			transform->position += m_velocity;
			transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(point));
		}
	}
}

void Game::Hare::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
		transform->position -= m_velocity;
	if (game_object.getName() == "carrot")
		m_is_angry = true;
	if (game_object.getName() == "wolf")
		Game::EventManager::getInstance()->destroy(getUUID());
}
Game::EntityType Game::Hare::getType()
{
	return type;
}
