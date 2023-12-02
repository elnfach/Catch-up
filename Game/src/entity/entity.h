#pragma once
#include "entity_type.h"
#include "components/colliders/collider.h"
#include "script_behaviour.h"
#include "BoxCollider.h"

class Entity : public Engine::ScriptBehaviour
{
protected:
	EntityType type;
	BoxCollider* collider;
public:
	Entity();
	Entity(double x, double y);
	~Entity();

	/*virtual bool is_collided(BoxCollider* collider) = 0;
	virtual BoxCollider* getCollider() = 0;
	virtual void updateCollider(Engine::Vector2f start, Engine::Vector2f end) = 0;*/

	virtual EntityType getType()
	{
		return type;
	}
};

Entity::Entity()
{
	collider = nullptr;
	type = EntityType::UNKNOWN;
}

inline Entity::Entity(double x, double y) : ScriptBehaviour()
{
	collider = nullptr;
	type = EntityType::UNKNOWN;
}

Entity::~Entity()
{
}