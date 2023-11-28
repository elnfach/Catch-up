#pragma once
#include "entity_type.h"
#include "components/colliders/collider.h"
#include "script_behaviour.h"
#include "components/vector2f.h"

class Entity : Engine::ScriptBehaviour
{
protected:
	double x;
	double y;

	EntityType type;
	Engine::Collider* collider;
public:
	Entity();
	Entity(double x, double y);
	~Entity();

	virtual bool is_collided(Engine::BoxCollider* collider) = 0;
	virtual Engine::BoxCollider* getCollider() = 0;
	virtual void updateCollider(Engine::Vector2f start, Engine::Vector2f end) = 0;

	virtual EntityType getType()
	{
		return type;
	}

private:

};

Entity::Entity()
{
	x = 0;
	y = 0;
	collider = nullptr;
	type = EntityType::UNKNOWN;
}

inline Entity::Entity(double x, double y)
{
	this->x = x;
	this->y = y;
	collider = nullptr;
	type = EntityType::UNKNOWN;
}

Entity::~Entity()
{
}