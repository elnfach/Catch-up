#pragma once

#include "entity/entity.h"

namespace Game
{
	class EntityBody : public Entity
	{
	public:
		EntityBody();
		EntityBody(Engine::Vector2f start_position, Engine::Vector2f head_size);
		~EntityBody();

		EntityType getType() override;
	private:

	};
}