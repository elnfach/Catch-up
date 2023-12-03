#pragma once

#include "components\rigidbody\rigid_body.h"

#include "box2d/b2_body.h"
#include <iostream>

namespace Engine {

	namespace Utils {

		inline b2BodyType Rigidbody2DTypeToBox2DBody(RigidBody::BodyType bodyType)
		{
			switch (bodyType)
			{
			case RigidBody::BodyType::Static:    return b2_staticBody;
			case RigidBody::BodyType::Dynamic:   return b2_dynamicBody;
			case RigidBody::BodyType::Kinematic: return b2_kinematicBody;
			}

			std::cout << "Unknown body type" << std::endl;
			
			return b2_staticBody;
		}

		inline RigidBody::BodyType Rigidbody2DTypeFromBox2DBody(b2BodyType bodyType)
		{
			switch (bodyType)
			{
			case b2_staticBody:    return RigidBody::BodyType::Static;
			case b2_dynamicBody:   return RigidBody::BodyType::Dynamic;
			case b2_kinematicBody: return RigidBody::BodyType::Kinematic;
			}

			std::cout << "Unknown body type" << std::endl;
			return RigidBody::BodyType::Static;
		}
	}
}