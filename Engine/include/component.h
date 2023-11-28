#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Transform;
	class GameObject;
	class ScriptBehaviour;
	class Component : public Object
	{
	protected:
		enum class ComponentType
		{
			Unknown = 0,
			ScriptBehaviour,
			Transform,
			Drawable,
			BoxCollider2D
		};
	public:
		Component();
		Component(ComponentType type);
		~Component();

		GameObject* game_object;
		Transform* transform;
	private:
		ComponentType component_type;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H