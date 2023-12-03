#pragma once
#include <string>
#include <utility>
#include "components\vector2f.h"

namespace Engine
{
	class BoxCollider
	{	
	public:
		BoxCollider();
		~BoxCollider();

		Vector2f offset;
		Vector2f size;

		float density = 1.0f;
		float friction = 0.5f;
		float restitution = 0.0f;
		float restitutionThreshold = 0.5f;

		void* runtime_fixture = nullptr;
	};
}