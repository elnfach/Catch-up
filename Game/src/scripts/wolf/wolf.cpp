#include "wolf/wolf.h"

#include <corecrt_math_defines.h>
#include "time_step.h"
#include "random.h"
#include "event/event_manager.h"

Wolf::Wolf() : Entity()
{
	name = "wolf";
	type = EntityType::WOLF;

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>();

	//body = new EntityBody(transform->position, box_collider->size);
}

Wolf::Wolf(double x, double y, int width, int height) : Entity()
{
	name = "wolf";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));	

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	//body = new EntityBody(transform->position, box_collider->size);
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

void Wolf::start()
{
}

void Wolf::update()
{
	Engine::Vector2f direction = calcDirection(transform->rotation);					// calc direction by rotation
	Engine::Vector2f a = Engine::Vector2f(direction.x, direction.y).normalized();		// wolf
	Engine::Vector2f b;
	for (auto& i : Game::EventManager::getInstance()->getHareTeam())
	{
		if (m_visibility_range >= Engine::Vector2f(i - transform->position).magnitude())
		{
			b = Engine::Vector2f(i - transform->position).normalized();						// hare
		}
	}
	
	float angle = acos(a.x * b.x + a.y * b.y) * 180.0f * M_PI;

	m_velocity = Engine::Vector2f(direction.x, direction.y) * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;

	if (m_angle / 2 > angle)
	{
		transform->position += b * Engine::Timestep::getInstance()->getDeltaTime() * m_speed;
		transform->rotation = Engine::Vector3f(0.0f, 0.0f, calcDirectionAngle(b));
	} else {
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

void Wolf::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
		transform->position -= m_velocity;
	if (game_object.getName() == "hare")
	{
		
	}
}

void Wolf::onCollisionExit(GameObject game_object)
{
}

EntityType Wolf::getType()
{
	return type;
}
