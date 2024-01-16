#pragma once

#include <utility>
#include <math.h>
#include <list>
#include <iostream>

#include "components/vector2f.h"
#include "entity/entity.h"
#include "entity\entity_type.h"
#include <vector>
#include "components/rigidbody/rigid_body.h"
#include "components/colliders/box_collider.h"
#include "components/transform.h"

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

class RayCast : public Entity
{
	float m_x;
	float m_y;
	float lenght;
	bool is_collided;

	Engine::RigidBody* m_rigid_body;
	Engine::BoxCollider* m_box_collider;

	EntityType type;

public:
	RayCast();
	RayCast(Engine::Vector2f size, Engine::Vector2f offset);
	~RayCast();

	void update(Engine::Vector2f position, Engine::Vector3f rotation);

	bool onCollisionWithWall() const;

	void onCollisionEnter(GameObject game_object);

	EntityType getType()
	{
		return type;
	}
};