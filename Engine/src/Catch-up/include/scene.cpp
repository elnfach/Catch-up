#include "scene.h"
#include "game_object.h"
#include "Catch-up\renderer\renderer.h"


void Engine::Scene::createGameObject(GameObject& object)
{
    object.addComponent<Transform>();

    m_game_objects_map[UUID()] = object;
}

void Engine::Scene::start()
{
}

void Engine::Scene::update()
{

    Renderer::update();
}