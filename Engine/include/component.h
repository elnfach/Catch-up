#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Component : public Object
	{
	protected:

		enum class ComponentType
		{
			Unknown = 0,
			Transform = 1,
			Drawable = 2,
			BoxCollider2D = 3
		};
	public:
		Component();
		Component(ComponentType type);
		~Component();


	private:
		ComponentType component_type;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H