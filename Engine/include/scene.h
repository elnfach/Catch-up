#ifndef CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H
#define CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H

#include <entt\entt.hpp>

#include <string>

#include "uuid.h"
#include "component.h"

namespace Engine
{
    class GameObject;
    class Scene
    {
    public:
        static Scene* getInstance() {
            static Scene instance;
            return &instance;
        }
        Scene(const Scene&) = delete;
        Scene(const Scene&&) = delete;

        void createGameObject(GameObject& object);

        template<class T>
        void addComponent(GameObject entity, T& component)
        {

        }

        template<class T>
        bool hasComponent(entt::entity entity)
        {

        }

        void start();
        void update();

    private:
        Scene() {}
        ~Scene() {}

        entt::registry m_game_objects;
        std::unordered_map<UUID, entt::entity> m_game_objects_map;

        friend GameObject;
    };
}

#endif // !CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H