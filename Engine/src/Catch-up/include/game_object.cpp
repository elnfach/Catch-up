#include "game_object.h"
#include "scene.h"

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

void Engine::GameObject::print()
{
	std::cout << "GameObject name: " << name << std::endl;
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

template<class T, class ...Args>
T& Engine::GameObject::addOrReplaceComponent(Args && ...args)
{
	T& component = m_scene->m_game_objects.emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
	m_scene->addComponent(*this, component);
	return component;
}

template<class T>
void Engine::GameObject::removeComponent()
{
	std::cout << "Entity does not have component!" << std::endl;
	m_scene->m_game_objects.remove<T>(m_entity);
}