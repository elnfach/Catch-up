#include "Catch-up/renderer/renderer.h"
#include "components/colliders/box_collider.h"
#include "components/drawable/rectangle_drawable.h"
#include "components/id/id_component.h"
#include "components/rigidbody/rigid_body.h"
#include "game_object.h"
#include "scene.h"

void Engine::Scene::createGameObject(GameObject& object)
{
	createGameObjectWithUUID(UUID(), object);
}

void Engine::Scene::createGameObjectWithUUID(UUID uuid, GameObject& object)
{
	object.addComponent<IDComponent>(uuid);
	object.addComponent<Transform>();
	object.addComponent<RectangleDrawable>();

	m_game_object_list.push_back(&object);
	m_entity_map[uuid] = object;
}

void Engine::Scene::destroyGameObject()
{
	for (auto& i : m_pending_deletion_list)
	{
		std::cout << std::format("Что удаляется: {0}\n", i.operator size_t());
		std::cout << "До удаления:\n";
		for (auto j = m_game_object_list.begin(); j != m_game_object_list.end();)
		{
			std::cout << std::format("{0} | {1}, {2}\n", (uint32_t)(**j), (*j)->getName(), (*j)->getUUID().operator size_t());
			if ((*j)->getUUID() == i)
			{
				m_entity_map.erase(i);
				m_game_objects.destroy(**j);
				j = m_game_object_list.erase(j);
			}
			else
				++j;
		}
		std::cout << "После удаления:\n";
		for (auto j = m_game_object_list.begin(); j != m_game_object_list.end();++j)
		{
			std::cout << std::format("{0} | {1}, {2}\n", (uint32_t)(**j), (*j)->getName(), (*j)->getUUID().operator size_t());
		}
	}
	
	m_pending_deletion_list.clear();
}

Engine::GameObject Engine::Scene::getGameObjectByUUID(UUID uuid)
{
	if (m_entity_map.find(uuid) != m_entity_map.end())
		return { m_entity_map.at(uuid), this };

	return {};
}

void Engine::Scene::start()
{
	physicsStart();
	for (auto& game_object : m_game_object_list)
	{
		game_object->start();
	}
}

void Engine::Scene::update()
{
	//	***
	// 
	//	Physics
	//
	//	***
	{
		auto view = m_game_objects.view<Engine::RigidBody>();
		for (auto i : view)
		{
			GameObject game_object_1 = { i, this };
			auto& rigid_body_1 = game_object_1.getComponent<RigidBody>();
			auto& transform_1 = game_object_1.getComponent<Transform>();
			auto& box_collider_1 = game_object_1.getComponent<BoxCollider>();

			for (auto j : view)
			{
				GameObject game_object_2 = { j, this };
				auto& rigid_body_2 = game_object_2.getComponent<RigidBody>();
				auto& transform_2 = game_object_2.getComponent<Transform>();
				auto& box_collider_2 = game_object_2.getComponent<BoxCollider>();

				if (game_object_1.getUUID() != game_object_2.getUUID() &&
					(rigid_body_1.type != RigidBody::BodyType::Static || rigid_body_2.type != RigidBody::BodyType::Static))
				{
					float x_offset_1 = box_collider_1.size.x / 2;
					float y_offset_1 = box_collider_1.size.y / 2;

					float x_offset_2 = box_collider_2.size.x / 2;
					float y_offset_2 = box_collider_2.size.y / 2;

					//	***
					//	
					//	Primitive collision handling system.
					// 
					//	Detail:
					//	This system does not take into account the rotation of the GameObject.
					//	
					//	***
					if (transform_1.position.x - x_offset_1 <= transform_2.position.x + x_offset_2 &&
						transform_1.position.y - y_offset_1 <= transform_2.position.y + y_offset_2 &&
						transform_1.position.x + x_offset_1 >= transform_2.position.x - x_offset_2 &&
						transform_1.position.y + y_offset_1 >= transform_2.position.y - y_offset_2	)
					{
						for (auto item : m_game_object_list)
						{
							for (auto item2 : m_game_object_list)
							{
								if (item->getUUID() == game_object_1.getUUID() &&
									item2->getUUID() == game_object_2.getUUID())
								{
									item->onCollisionEnter(*item2);
								}
							}
						}
					}
				}
			}
		}
	}

	destroyGameObject();

	{
		for (auto& i : m_game_object_list)
		{
			i->update();
		}
	}
	
	renderScene();
}

void Engine::Scene::renderScene()
{
	Renderer::clear();

	auto view = m_game_objects.view<Transform, RectangleDrawable>();
	for (auto entity : view)
	{
		auto [transform, rect] = view.get<Transform, RectangleDrawable>(entity);
		Renderer::drawRectangle(transform, rect.size, rect.color);
	}

	Renderer::present();
}


void Engine::Scene::physicsStart()
{

}

void Engine::Scene::onPhysicsStop()
{
	m_game_object_list.clear();
}
