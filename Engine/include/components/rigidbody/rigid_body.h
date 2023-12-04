#pragma once

#include "component.h"

namespace Engine
{
	class RigidBody : public Component
	{
	public:
		enum class BodyType { Static = 0, Dynamic, Kinematic };

		RigidBody();
		RigidBody(const BodyType type, bool fixed_rotation);
		RigidBody(const RigidBody& rb);
		~RigidBody();

		BodyType type;
		bool fixed_rotation;

		void* runtime_body;
	};
}