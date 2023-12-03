#pragma once

#include "uuid.h"
#include "component.h"

namespace Engine
{
	class IDComponent : public Component
	{
	public:
		UUID ID;

		IDComponent() = default;
		IDComponent(UUID uuid) : ID(uuid) {}
		IDComponent(const IDComponent&) = default;
	};
}