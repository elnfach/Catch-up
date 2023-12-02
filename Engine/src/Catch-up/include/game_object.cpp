#include <SDL.h>

#include "game_object.h"
#include "scene.h"

Engine::GameObject::GameObject(entt::entity handle, Scene* scene) : m_entity(handle), m_scene(scene)
{
}

Engine::GameObject::~GameObject()
{

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

template<typename T>
inline bool Engine::GameObject::hasComponent()
{
	return m_scene->m_game_objects.all_of<T>(m_entity);
}

template<typename T>
T& Engine::GameObject::getComponent()
{
	std::cout << "GameObject does not have component!" << std::endl;
	return m_scene->m_game_objects.get<T>(m_entity);
}

template<typename T, typename ...Args>
T& Engine::GameObject::addComponent(Args && ...args)
{
	std::cout << "GameObject already has component!" << std::endl;
	T& component = m_scene->m_game_objects.emplace<T>(m_entity, std::forward<Args>(args)...);
	m_scene->addComponent(*this, component);
	return component;
}

template<typename T, typename ...Args>
T& Engine::GameObject::addOrReplaceComponent(Args && ...args)
{
	T& component = m_scene->m_game_objects.emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
	m_scene->addComponent(*this, component);
	return component;
}

template<typename T>
void Engine::GameObject::removeComponent()
{
	std::cout << "Entity does not have component!" << std::endl;
	m_scene->m_game_objects.remove<T>(m_entity);
}