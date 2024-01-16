#pragma once

#include "entity/entity.h"
#include "components/rigidbody/rigid_body.h"

namespace Game
{
	class Carrot : public Entity
	{
	public:
		Carrot();
		Carrot(double x, double y, int width, int height);
		~Carrot();

		void onCollisionEnter(GameObject game_object) override;
		EntityType getType() override;
	private:
		Engine::RigidBody* rigid_body;
		Engine::BoxCollider* box_collider;
	};
}