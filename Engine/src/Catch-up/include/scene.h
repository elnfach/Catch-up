#ifndef CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H
#define CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H

#include <entt\entt.hpp>

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

        template<typename T>
        void addComponent(GameObject entity, T& component);

        template<typename T>
        bool hasComponent(entt::entity entity);

        void start();
        void update();

    private:
        Scene* m_ptr_component_base = nullptr;
        Scene() {}
        ~Scene() {}

        entt::registry m_game_objects;

        friend GameObject;
    };
}

#endif // !CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H