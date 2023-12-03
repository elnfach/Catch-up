#include "components\rigidbody\rigid_body.h"

Engine::RigidBody::RigidBody()
{
	type = BodyType::Dynamic;
	fixed_rotation = false;
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
