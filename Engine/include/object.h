#ifndef CATCH_UP_ENGINE_INCLUDE_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_OBJECT_H

#include <string>
#include <vector>
#include "application.h"

namespace Engine
{
	class Object : public Application
	{
		static int m_id;
		int id;

		enum class ObjectType;
		ObjectType type;

		std::vector<Object*> objects;
	protected:
		Object();
		Object(ObjectType type);
		std::string name;

		inline std::string toString() { return name; }
		inline int getInstanceID() { return id; }
		inline ObjectType getInstanceType() { return type; }

		virtual void draw() {}
		void update() override;

		static void destroy(Object* object);

		enum class ObjectType {
			Unknown = 0,
			Object = 1,
			Component = 2,
			GameObject = 3,
			Transform = 4,
			Collider2D = 5,
			BoxCollider2D = 6
		};
	public:
		virtual ~Object();
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_OBJECT_H