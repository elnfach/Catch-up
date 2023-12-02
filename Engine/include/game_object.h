#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include <functional>
#include <iostream>

#include "entt.hpp"

#include "scene.h"
#include "components/drawable/rectangle_drawable.h"

namespace Engine
{
	class GameObject : public Object
	{
	public:
		GameObject();
		GameObject(const GameObject& other) = default;
		GameObject(entt::entity handle, Scene* scene);
		~GameObject();

		void print();

		template<class T>
		bool hasComponent();

		template<class T>
		T& getComponent();

		template<class T, class... Args>
		T& addComponent(Args && ...args)
		{
			std::cout << "GameObject already has component!" << std::endl;
			T& component = m_scene->m_game_objects.emplace<T>(m_entity, std::forward<Args>(args)...);
			m_scene->addComponent(*this, component);
			return component;
		}

		template<class T, class... Args>
		T& addOrReplaceComponent(Args&&... args);

		template<class T>
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