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
	transform->rotation += Engine::Vector3f(0.0f, 0.0f, 10.0f) * Engine::Timestep::getInstance()->getDeltaTime() * 5.0f;
	float angleInRadians = transform->rotation.z * 3.14 / 180.0f;
	float cosAngle = cos(angleInRadians);
	float sinAngle = sin(angleInRadians);

	float dirX = cosAngle;
	float dirY = sinAngle;

	float length = sqrt(dirX * dirX + dirY * dirY);
	if (length != 0.0f) {
		dirX /= length;
		dirY /= length;
	}

	float speed = 10.0f;
	float moveX = dirX * speed;
	float moveY = dirY * speed;

	if (vector)
	{
		transform->position += (vec * (-1)) * Engine::Timestep::getInstance()->getDeltaTime();
		return;
	}
	transform->position += Engine::Vector2f(
		moveX, 
		moveY) * Engine::Timestep::getInstance()->getDeltaTime();
}

void Wolf::onCollisionEnter(GameObject game_object)
{
	std::cout << name << " collided with " << game_object.getName() << std::endl;
	vector = (vector) ? false : true;
}

EntityType Wolf::getType()
{
	return type;
}
