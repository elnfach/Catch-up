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
		virtual void onCollisionEnter(GameObject* game_object) {}

		template<class T>
		bool hasComponent()
		{
			return m_scene->m_game_objects.all_of<T>(m_entity);
		}

		template<class T>
		T& getComponent()
		{
			if (hasComponent<T>())
			{
				return m_scene->m_game_objects.get<T>(m_entity);
			}
			std::cout << hasComponent<T>() << "GameObject does not have component!" << std::endl;
		}

		template<class T, class... Args>
		T& addComponent(Args && ...args)
		{
			if (hasComponent<T>())
			{
				std::cout << hasComponent<T>() << "GameObject already has component!" << std::endl;
			}
			T& component = m_scene->m_game_objects.emplace<T>(m_entity, std::forward<Args>(args)...);
			return component;
		}

		template<class T, class... Args>
		T& addOrReplaceComponent(Args&&... args)
		{
			T& component = m_scene->m_game_objects.emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
			return component;
		}

		template<class T>
		void removeComponent()
		{
			if(!hasComponent<T>()) std::cout << "Entity does not have component!" << std::endl;
			m_scene->m_game_objects.remove<T>(m_entity);
		}

		operator bool() const;
		operator entt::entity() const;
		operator unsigned int() const;

	private:
		entt::entity m_entity{ entt::null };
		Scene* m_scene = nullptr;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H