#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Transform;
	class GameObject;
	class ComponentBase;
	class ScriptBehaviour;
	class Component : public Object, public ComponentBase
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

		virtual void start() {}
		virtual void update() {}
		
		virtual Component* getComponent() = 0;

		GameObject* game_object;
		Transform* transform;
	private:
		ComponentType component_type;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H