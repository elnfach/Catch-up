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

	m_velocity = Engine::Vector2f(direction.x, direction.y) * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;

	if (m_angle / 2 > angle)
	{
		if (m_is_angry)
		{
			isAngry(dir);
		}
		else
		{
			transform->position += b * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
			transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(b));
		}
	}
	else {
		Engine::Random random;
		if (random.Next(100) > 30) {
			transform->rotation += Engine::Vector3f(0.0f, 0.0f, 10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
		}
		else {
			transform->rotation += Engine::Vector3f(0.0f, 0.0f, -10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
		}
		transform->position += m_velocity;
	}
}

void Game::Hare::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
		transform->position -= m_velocity;
	//if (game_object.getName() == "carrot")
	//	// m_is_angry = true;
	if (game_object.getName() == "wolf")
		Game::EventManager::getInstance()->destroy(getUUID());
}
Game::EntityType Game::Hare::getType()
{
	return type;
}
