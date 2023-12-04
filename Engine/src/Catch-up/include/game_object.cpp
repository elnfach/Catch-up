#include "game_object.h"
#include "scene.h"
#include "components\id\id_component.h"

Engine::GameObject::GameObject()
{
	m_scene = Scene::getInstance();
	if (m_scene != nullptr)
	{
		m_entity = m_scene->m_game_objects.create();
		Scene::getInstance()->createGameObject(*this);
	}
}

Engine::GameObject::GameObject(entt::entity handle, Scene* scene) : m_entity(handle), m_scene(Scene::getInstance())
{
}

Engine::GameObject::~GameObject()
{
	
}

void Engine::GameObject::destroy(GameObject* game_object)
{
	m_scene->m_pending_deletion_list.push_back(game_object);
}

Engine::GameObject::operator bool() const
{
	return m_entity != entt::null;
}

Engine::GameObject::operator entt::entity() const
{
	return m_entity;
}

Engine::GameObject::operator unsigned int() const
{
	return (unsigned int)m_entity;
}

Engine::UUID Engine::GameObject::GetUUID()
{
	return getComponent<IDComponent>().ID;
}