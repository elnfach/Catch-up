#include "wolf/wolf.h"

#include <corecrt_math_defines.h>
#include "time_step.h"
#include "random.h"
#include "event/event_manager.h"

Game::Wolf::Wolf() : Entity()
{
	name = "wolf";
	type = EntityType::WOLF;

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>();
}

Game::Wolf::Wolf(double x, double y, int width, int height) : Entity()
{
	name = "wolf";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));	

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	drawable->color = Engine::Vector4f(255, 0, 0, 0);

	type = EntityType::WOLF;
}

Game::Wolf::Wolf(double x, double y, int width, int height, std::vector<Engine::Vector2f> map)
{
	name = "wolf";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	drawable->color = Engine::Vector4f(255, 0, 0, 0);

	m_map = map;
	type = EntityType::WOLF;
}

Game::Wolf::~Wolf()
{
	delete rigid_body;
	delete box_collider;
}

void Game::Wolf::start()
{
}

void Game::Wolf::update()
{
	Engine::Vector2f direction = calcDirection(transform->rotation);					// calc direction by rotation
	Engine::Vector2f a = Engine::Vector2f(direction.x, direction.y).normalized();		// wolf
	Engine::Vector2f b;
	float min = FLT_MAX;
	float temp_point;
	for (auto& i : Game::EventManager::getInstance()->getHareTeam())
	{
		temp_point = Engine::Vector2f(i - transform->position).magnitude();
		if (min > temp_point)
		{
			min = temp_point;
			b = Engine::Vector2f(i - transform->position).normalized();						// hare
		}
	}

	float angle = acos(a.x * b.x + a.y * b.y) * 180.0f * M_PI;

	Engine::Vector2f point_to_carrot;
	for (auto& i : Game::EventManager::getInstance()->getCarrots())
	{
		temp_point = Engine::Vector2f(i - transform->position).magnitude();
		if (min > temp_point)
		{
			min = temp_point;
			point_to_carrot = Engine::Vector2f(i - transform->position).normalized();						// carrot
		}
	}

	float angle_to_carrot = acos(a.x * point_to_carrot.x + a.y * point_to_carrot.y) * 180.0f * M_PI;

	min = FLT_MAX;
	Engine::Vector2f point;
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

	if (m_angle / 2 > angle)
	{
		transform->position += b * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
		transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(b));
	}
	else if (angle_to_carrot / 2 > angle) 
	{
		transform->position += point_to_carrot * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
		transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(point_to_carrot));
	} else {
		transform->position += m_velocity;
		transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(point));
		if (Engine::Vector2f(point - transform->position).magnitude() < 25.0F)
			is_reached = true;
	}
}

void Game::Wolf::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
		transform->position -= m_velocity;
}

void Game::Wolf::onCollisionExit(GameObject game_object)
{
}

Game::EntityType Game::Wolf::getType()
{
	return type;
}
