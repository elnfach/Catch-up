#include "scene.h"
#include "game_object.h"
#include "Catch-up\core\time_step.h"
#include "Catch-up\renderer\renderer.h"
#include "components\colliders\box_collider.h"
#include "components\rigidbody\rigid_body.h"
#include "Catch-up\physics\physics2d.h"
#include "Catch-up\physics\collision_listener.h"



#include "box2d\b2_contact.h"
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_circle_shape.h"
#include "components\id\id_component.h"


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
	m_game_objects_map[uuid] = object;
}

void Engine::Scene::destroyGameObject()
{
	for (auto i = m_pending_deletion_list.begin(); i != m_pending_deletion_list.end(); i++)
	{
		m_game_objects_map.erase((*i)->GetUUID());
		m_game_objects.destroy(*(*i));
		delete (*i);
	}
	m_pending_deletion_list.clear();
}

Engine::GameObject Engine::Scene::getGameObjectByUUID(UUID uuid)
{
	if (m_game_objects_map.find(uuid) != m_game_objects_map.end())
		return { m_game_objects_map.at(uuid), this };

	return {};
}

void Engine::Scene::start()
{
	physicsStart();
}

void Engine::Scene::update(Engine::Timestep ts)
{
	{
		auto view = m_game_objects.view<Engine::BoxCollider>();
		for (auto i : view)
		{
			GameObject game_object_1 = { i, this };
			auto& transform_1 = game_object_1.getComponent<Transform>();
			auto& box_collider_1 = game_object_1.getComponent<BoxCollider>();

			for (auto j : view)
			{
				GameObject game_object_2 = { j, this };
				auto& transform_2 = game_object_2.getComponent<Transform>();
				auto& box_collider_2 = game_object_2.getComponent<BoxCollider>();

				if (game_object_1.GetUUID() != game_object_2.GetUUID())
				{
					if (transform_1.position.x <= transform_2.position.x + box_collider_2.size.x &&
						transform_1.position.x + box_collider_1.size.x >= transform_2.position.x &&
						transform_1.position.y <= transform_2.position.y + box_collider_2.size.y &&
						transform_1.position.y + box_collider_1.size.y >= transform_2.position.y)
					{
						for (auto* go_1 : m_game_object_list)
						{
							for (auto* go_2 : m_game_object_list)
							{
								if (go_1->GetUUID() == game_object_1.GetUUID() && 
									go_2->GetUUID() == game_object_2.GetUUID())
								{
									go_1->onCollisionEnter(*go_2);
								}
							}
						}
					}
				}
			}
		}
		destroyGameObject();
	}
	
	renderScene();
}

void Engine::Scene::renderScene()
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


void Engine::Scene::physicsStart()
{

}

void Engine::Scene::onPhysicsStop()
{
	delete listener;
	delete m_physics_world;
	m_physics_world = nullptr;
}
