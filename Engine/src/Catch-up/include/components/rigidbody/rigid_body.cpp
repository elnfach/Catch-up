#include "components\rigidbody\rigid_body.h"

Engine::RigidBody::RigidBody()
{
	type = BodyType::Static;
	fixed_rotation = false;
	runtime_body = nullptr;
}

Engine::RigidBody::RigidBody(const BodyType type, bool fixed_rotation) : type(type), fixed_rotation(fixed_rotation)
{
	runtime_body = nullptr;
}

Engine::RigidBody::RigidBody(const RigidBody& rb)
{
	type = rb.type;
	fixed_rotation = rb.fixed_rotation;
	runtime_body = rb.runtime_body;
}

Engine::RigidBody::~RigidBody()
{
}
