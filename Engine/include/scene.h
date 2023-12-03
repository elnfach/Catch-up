#ifndef CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H
#define CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H

#include <entt\entt.hpp>

#include <string>

#include "uuid.h"
#include "component.h"

class b2World;
namespace Engine
{
    class CollisionListener;
    class Timestep;
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

        void start();
        void update(Timestep ts);
        void renderScene();
        void physicsStart();
        void onPhysicsStop();

    private:
        Scene() {}
        ~Scene() {}

        int m_step_frames = 60;

        b2World* m_physics_world = nullptr;
        CollisionListener* listener = nullptr;

        entt::registry m_game_objects;
        std::unordered_map<UUID, entt::entity> m_game_objects_map;

        friend GameObject;
    };
}

#endif // !CATCH_UP_ENGINE_SRC_INCLUDE_COMPONENT_BASE_H