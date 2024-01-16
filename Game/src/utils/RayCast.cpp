#include "utils/RayCast.h"

RayCast::RayCast()
{
	m_x = 0;
	m_y = 0;
	is_collided = false;
	lenght = 0;
	m_rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	m_box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(1.0f, 1.0f));
	type = EntityType::UNKNOWN;

	transform->offset = { 25.0f , 0.0f };

	drawable->color = Engine::Vector4f(255, 0, 0, 255);
}

RayCast::RayCast(Engine::Vector2f size, Engine::Vector2f offset)
{
	m_x = 0;
	m_y = 0;
	lenght = 0;
	is_collided = false;
	m_rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	m_box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(size.x + offset.x, size.y + offset.y));
	type = EntityType::UNKNOWN;

	transform->offset = offset;

	drawable->color = Engine::Vector4f(255, 0, 0, 255);
	drawable->size = size;
}

RayCast::~RayCast()
{
}

void RayCast::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
	{
		is_collided = true;
	}
	else
	{
		is_collided = false;
	}
}

void RayCast::update(Engine::Vector2f position, Engine::Vector3f rotation)
{
	transform->position = position;
	transform->rotation = rotation + Engine::Vector3f(0.0f, 0.0f, 90.0f);
}

bool RayCast::onCollisionWithWall() const
{
	if (is_collided)
	{
		return true;
	}
	return false;
}
