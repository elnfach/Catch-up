#pragma once

#include <time.h>
#include <vector>
#include <functional>

#include "entity/entity.h"

#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"
#include "components\rigidbody\rigid_body.h"
#include "body.h"

namespace Game
{
	class Hare : public Entity
	{
	public:
		Hare();
		Hare(double x, double y, int width, int height);
		~Hare();

		void start() override;
		void update() override;
		void onCollisionEnter(GameObject game_object) override;

		EntityType getType() override;
	private:
		Engine::RigidBody* rigid_body;
		Engine::BoxCollider* box_collider;
		float m_angle = 150.0f;
		float m_speed = 100.0f;
		Engine::Vector2f m_velocity = Engine::Vector2f(0.0f, 0.0f);
	};
}