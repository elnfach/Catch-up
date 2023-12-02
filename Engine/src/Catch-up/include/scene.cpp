#include "scene.h"
#include "game_object.h"
#include "Catch-up\renderer\renderer.h"


void Engine::Scene::createGameObject(GameObject& object)
{
    object.addComponent<Transform>();
    object.addComponent<RectangleDrawable>();

    m_game_objects_map[UUID()] = object;
}

void Engine::Scene::start()
{
}

void Engine::Scene::update()
{
	Renderer::clear(Vector4f(0, 0, 0, 0));

	auto view = m_game_objects.view<Transform, RectangleDrawable>();
	for (auto entity : view)
	{
		auto [transform, rect] = view.get<Transform, RectangleDrawable>(entity);
		Renderer::drawRectangle(transform, rect.size, rect.color);
	}

	Renderer::present();
}

template<class T>
void Engine::Scene::addComponent(Engine::GameObject entity, T& component)
{

}

template<class T>
bool Engine::Scene::hasComponent(entt::entity entity)
{
    return false;
}
