#pragma once
#include <time.h>
#include <vector>
#include <functional>

#include "entity/entity.h"

#include "components\transform.h"
#include "components\drawable\rectangle_drawable.h"
#include "components\rigidbody\rigid_body.h"
#include "body.h"
#include <map/map.h>

namespace Game
{
	class Wolf : public Entity
	{
	public:
		Wolf();
		Wolf(double x, double y, int width, int height);
		Wolf(double x, double y, int width, int height, std::vector<Engine::Vector2f> map);
		~Wolf();

		void start() override;
		void update() override;
		void onCollisionEnter(GameObject game_object) override;
		void onCollisionExit(GameObject game_object) override;

		EntityType getType() override;
	private:
		Engine::RigidBody* rigid_body;
		Engine::BoxCollider* box_collider;

		EntityBody* body = nullptr;
		float m_angle = 150.0f;
		float m_visibility_range = 2000.0f;
		float m_speed = 100.0f;
		bool is_reached = true;
		std:: vector<Engine::Vector2f> m_map;
		Engine::Vector2f m_velocity = Engine::Vector2f(0.0f, 0.0f);
	};
}