#pragma once

#include "component.h"
#include "components\vector2f.h"

namespace Engine
{
	class BoxCollider : public Component
	{	
	public:
		BoxCollider();
		BoxCollider(Vector2f size);
		~BoxCollider();

		inline std::string toString() const override { return name; }
		inline int getInstanceID() const override { return id; }

		Vector2f offset;
		Vector2f size;

		float density = 1.0f;
		float friction = 0.5f;
		float restitution = 0.0f;
		float restitutionThreshold = 0.5f;

		void* runtime_fixture = nullptr;
	};
}