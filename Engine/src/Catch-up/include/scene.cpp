#include "scene.h"
#include "Catch-up\renderer\renderer.h"

void Engine::Scene::start()
{
}

void Engine::Scene::update()
{

    Renderer::update();
}

template<typename Transform>
bool Engine::Scene::hasComponent(entt::entity entity)
{
    return m_game_objects.all_of<Transform>(entity);
}