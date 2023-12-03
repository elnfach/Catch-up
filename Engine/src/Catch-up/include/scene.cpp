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


void Engine::Scene::createGameObject(GameObject& object)
{
    object.addComponent<Transform>();
    object.addComponent<RectangleDrawable>();
    object.addComponent<RigidBody>();
    object.addComponent<BoxCollider>();

    m_game_objects_map[UUID()] = object;
}

void Engine::Scene::start()
{
	physicsStart();
}

void Engine::Scene::update(Engine::Timestep ts)
{
	{
		const int32_t velocityIterations = 6;
		const int32_t positionIterations = 2;
		m_physics_world->Step(ts, velocityIterations, positionIterations);

		m_physics_world->SetContactListener(listener);
		auto view = m_game_objects.view<Engine::RigidBody>();
		for (auto e : view)
		{
			GameObject game_object = { e, this };
			auto& transform = game_object.getComponent<Transform>();
			auto& rigid_body = game_object.getComponent<RigidBody>();

			b2Body* body = (b2Body*)rigid_body.runtime_body;

			const auto& position = body->GetPosition();
			transform.position.x = position.x;
			transform.position.y = position.y;
			//transform.rotation.z = body->GetAngle();

			/*b2Vec2 newPosition;
			newPosition.x = transform.position.x;
			newPosition.y = transform.position.y;*/
			//body->SetTransform(newPosition, 0.0f);

			//std::cout << "X=" << position.x << ", Y=" << position.y << std::endl;

		}
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
	m_physics_world = new b2World({ 0.0f, 0.0f });

	auto view = m_game_objects.view<RigidBody>();
	
	listener = new CollisionListener();
	for (auto e : view)
	{
		GameObject game_object = { e, this };
		auto& transform = game_object.getComponent<Transform>();
		auto& rigid_body = game_object.getComponent<RigidBody>();

		b2BodyDef body_def;

		body_def.type = Utils::Rigidbody2DTypeToBox2DBody(rigid_body.type);
		body_def.position.Set(transform.position.x, transform.position.y);
		//body_def.angle = transform.rotation.z;

		b2Body* body = m_physics_world->CreateBody(&body_def);
		body->SetFixedRotation(rigid_body.fixed_rotation);
		rigid_body.runtime_body = body;

		if (game_object.hasComponent<BoxCollider>())
		{
			auto& box_collider = game_object.getComponent<BoxCollider>();

			b2PolygonShape box_shape;
			box_shape.SetAsBox(box_collider.size.x * transform.scale.x, box_collider.size.y * transform.scale.y, b2Vec2(box_collider.offset.x, box_collider.offset.y), 0.0f);

			b2FixtureDef fixture_def;
			fixture_def.shape = &box_shape;
			fixture_def.density = box_collider.density;
			fixture_def.friction = box_collider.friction;
			fixture_def.restitution = box_collider.restitution;
			fixture_def.restitutionThreshold = box_collider.restitutionThreshold;
			body->CreateFixture(&fixture_def);
		}
	}
}

void Engine::Scene::onPhysicsStop()
{
	delete listener;
	delete m_physics_world;
	m_physics_world = nullptr;
}
