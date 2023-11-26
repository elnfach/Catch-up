#pragma once
#include "entity_type.h"
#include "colliders/collider.h"

class Entity
{
protected:
	double x;
	double y;

	EntityType type;
	Collider* collider;
public:
	Entity() {}
	~Entity() {}

private:

};