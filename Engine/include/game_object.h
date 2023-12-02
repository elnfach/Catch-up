#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include <functional>
#include <iostream>

#include <entt\entt.hpp>

#include "components/drawable/rectangle_drawable.h"

namespace Engine
{
	class Scene;
	class GameObject : public Object
	{
	public:
		GameObject() = default;
		GameObject(const GameObject& other) = default;
		GameObject(entt::entity handle, Scene* scene);
		~GameObject();

		template<typename T>
		bool hasComponent();

		template<typename T>
		T& getComponent();

		template<typename T, typename... Args>
		T& addComponent(Args&&... args);

		template<typename T, typename... Args>
		T& addOrReplaceComponent(Args&&... args);

		template<typename T>
		void removeComponent();

		operator bool() const;
		operator entt::entity() const;
		operator unsigned int() const;


	private:
		entt::entity m_entity{ entt::null };
		Scene* m_scene = nullptr;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H