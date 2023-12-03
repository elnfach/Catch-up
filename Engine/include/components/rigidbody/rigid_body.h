#pragma once

#include "component.h"

namespace Engine
{
	class RigidBody : public Component
	{
	public:
		RigidBody();
		RigidBody(const RigidBody& rb);
		~RigidBody();

		enum class BodyType { Static = 0, Dynamic, Kinematic };
		BodyType type;
		bool fixed_rotation;

		void* runtime_body;
	};
}