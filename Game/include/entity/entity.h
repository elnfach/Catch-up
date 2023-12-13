#pragma once
#include "entity_type.h"
#include "script_behaviour.h"
#include <components/transform.h>
#include "components/drawable/rectangle_drawable.h"
#include <components/colliders/box_collider.h>

class Entity : public Engine::ScriptBehaviour
{
protected:
	EntityType type;
	Engine::Transform* transform;
	Engine::RectangleDrawable* drawable;
public:
	Entity();
	~Entity();

	Engine::Vector2f calcDirection(Engine::Vector3f rotation);
	float calcDirectionAngle(Engine::Vector2f direction);

	virtual EntityType getType() = 0;
};