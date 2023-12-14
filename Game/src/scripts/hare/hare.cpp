#include "hare/hare.h"

#include "catch_up.h"
#include "time_step.h"
#include "event/event_manager.h"
#include <random.h>

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
}

void Game::Hare::start()
{
}

void Game::Hare::update()
{
	Engine::Vector2f direction = calcDirection(transform->rotation);
	Engine::Vector2f dir = Engine::Vector2f(direction.x, direction.y).normalized();

	m_velocity = Engine::Vector2f(direction.x, direction.y) * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;

	Engine::Random random;
	if (random.Next(100) > 30) {
		transform->rotation += Engine::Vector3f(0.0f, 0.0f, 10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
	}
	else {
		transform->rotation += Engine::Vector3f(0.0f, 0.0f, -10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
	}
	transform->position += m_velocity;
}

void Game::Hare::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
	{
		transform->position -= m_velocity;
	}
	if (game_object.getName() == "wolf")
	{
		Game::EventManager::getInstance()->destroy(this->GetUUID());
	}
}

Game::EntityType Game::Hare::getType()
{
	return type;
}
