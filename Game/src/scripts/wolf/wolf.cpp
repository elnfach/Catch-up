#include "wolf/wolf.h"

#include "time_step.h"

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

	//body = new EntityBody(transform->position, box_collider->size);
	type = EntityType::WOLF;
}

Wolf::~Wolf()
{
}

void Wolf::move(Engine::Vector2f vec)
{
	srand(time(0));
	

	if (rand() % 10 > 5)
	{
		transform->rotation += Engine::Vector3f(0.0f, 0.0f, 10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
	}
	else {
		transform->rotation += Engine::Vector3f(0.0f, 0.0f, -10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 15.0f;
	}
	float angle_in_radians = transform->rotation.z * 3.14 / 180.0f;
	float cos_angle = cos(angle_in_radians);
	float sin_angle = sin(angle_in_radians);

	float dir_x = cos_angle;
	float dir_y = sin_angle;

	float length = sqrt(dir_x * dir_x + dir_y * dir_y);
	if (length != 0.0f) {
		dir_x /= length;
		dir_y /= length;
	}

	float speed = 500.0f;
	float move_x = dir_x * speed;
	float move_y = dir_y * speed;

	auto a = Engine::Vector2f(dir_x, dir_y).normalized();
	//auto b = Engine::Vector2f(other - transform->position).normalized();

	//float angle = acos(a.x * b.x + a.y * b.y) * 180.0f * 3.14159265358979323846;

	velocity = Engine::Vector2f(move_x, move_y) * Engine::Timestep::getInstance()->getDeltaTime();
	transform->position += velocity;
}

void Wolf::onCollisionEnter(GameObject game_object)
{
	if (game_object.getName() == "wall")
	{
		transform->position += velocity * (-1);
	}
}

void Wolf::onCollisionExit(GameObject game_object)
{
}

EntityType Wolf::getType()
{
	return type;
}
