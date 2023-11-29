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

		virtual void start() {
			for (size_t i = 0; i < component_list.size(); i++)
			{
				component_list[i]->start();
			}

		}
		virtual void update() {
			for (size_t i = 0; i < component_list.size(); i++)
			{
				component_list[i]->start();
			}

		}

		GameObject* game_object;
		Transform* transform;
	private:
		ComponentType component_type;
		std::vector<Component*> component_list;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H