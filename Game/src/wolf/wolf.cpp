#include "wolf/wolf.h"

Wolf::Wolf() : Entity()
{
	name = "wolf";
	type = EntityType::WOLF;

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>();

	//body = new EntityBody(transform->position, box_collider->size);
}

Wolf::Wolf(double x, double y, int width, int height) : Entity()
{
	name = "wolf";

	rigid_body = &addComponent<Engine::RigidBody>(Engine::RigidBody::BodyType::Dynamic, false);
	box_collider = &addComponent<Engine::BoxCollider>(Engine::Vector2f(width, height));

	transform->position.x = x;
	transform->position.y = y;
	drawable->size.x = width;
	drawable->size.y = height;

	ray_cast = new RayCast(Engine::Vector2f(1.0f, 25.0f), Engine::Vector2f(0.0f, - height));

	//body = new EntityBody(transform->position, box_collider->size);
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

void Wolf::move(Engine::Vector2f vec, Engine::Vector2f other, float deltaTime)
{
	//transform->rotation = Engine::Vector3f(0.0f, 0.0f, 0.0f);

	float angle_in_radians = transform->rotation.z * 3.14 / 180.0f;
	float cos_angle = cos(angle_in_radians);
	float sin_angle = sin(angle_in_radians);

	float x_dir = cos_angle;
	float y_dir = sin_angle;

	float length = sqrt(x_dir * x_dir + y_dir * y_dir);
	if (length != 0.0f) {
		x_dir /= length;
		y_dir /= length;
	}

	float speed = 200.0f;
	float moveX = x_dir * speed;
	float moveY = y_dir * speed;

	auto a = Engine::Vector2f(x_dir, y_dir).normalized();
	auto b = Engine::Vector2f(other - transform->position).normalized();

	float angle = acos(a.x * b.x + a.y * b.y) * 180.0f * 3.14159265358979323846;

	ray_cast->update(transform->position + Engine::Vector2f(x_dir, y_dir) * deltaTime * speed, transform->rotation);

	

	if (m_angle / 2 > angle)
	{
		transform->position += b * deltaTime * speed;
	}
	else
	{
		if (vector)
		{
			srand(time(0));
			if (rand() % 10 > 5) {
				transform->rotation += Engine::Vector3f(0.0f, 0.0f, 10.0f) * deltaTime * 5.0f;
			}
			else {
				transform->rotation += Engine::Vector3f(0.0f, 0.0f, -10.0f) * deltaTime * 5.0f;
			}
			transform->position += Engine::Vector2f(x_dir, y_dir) * deltaTime * speed;
		}
		else
		{
			transform->position += 0.0f;
		}
	}
}

void Wolf::onCollisionEnter(GameObject game_object)
{
	vector = (game_object.getName() == "wall") ? true : false;
}

EntityType Wolf::getType()
{
	return type;
}
