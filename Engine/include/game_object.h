#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include <format>
#include <iostream>

#include "entt.hpp"
#include "scene.h"

namespace Engine
{
	class GameObject : public Object
	{
	public:
		GameObject();
		GameObject(const GameObject& other) = default;
		GameObject(entt::entity handle, Scene* scene);
		~GameObject();

		std::string getName() const { return name; }
		virtual void start() {}
		virtual void update() {}
		virtual void onCollisionEnter(GameObject game_object) {}
		virtual void onCollisionExit(GameObject game_object) {}
		void destroy(UUID uuid);

		template<class T>
		bool hasComponent()
		{
			return m_scene->m_game_objects.all_of<T>(m_entity);
		}

		template<class T>
		T& getComponent()
		{
			if (!hasComponent<T>())
			{
				std::cout << std::format("GameObject {0} does not have component!", name) << std::endl;
				__debugbreak();
			}
			return m_scene->m_game_objects.get<T>(m_entity);
		}

		template<class T, class... Args>
		T& addComponent(Args && ...args)
		{
			if (hasComponent<T>())
			{
				std::cout << std::format("GameObject {0} already has component!", name) << std::endl;
				__debugbreak();
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
			if (!hasComponent<T>())
			{
				std::cout << std::format("GameObject {0} does not have component!", name) << std::endl;
				__debugbreak();
			}
			m_scene->m_game_objects.remove<T>(m_entity);
		}

		operator bool() const;
		operator entt::entity() const;
		operator unsigned int() const;

		UUID getUUID();

		bool operator==(const GameObject& other) const
		{
			return m_entity == other.m_entity && m_scene == other.m_scene;
		}

		bool operator!=(const GameObject& other) const
		{
			return !(*this == other);
		}
	private:
		entt::entity m_entity{ entt::null };
		Scene* m_scene = nullptr;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H