#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Transform;
	class GameObject;
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
		Transform* transform;
	public:
		Component();
		Component(ComponentType type);
		~Component();

		virtual void start() {}
		virtual void update() {}
		
		virtual Component* getComponent() {
			return nullptr;
		}
		
		GameObject* game_object;
	private:
		ComponentType component_type;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H