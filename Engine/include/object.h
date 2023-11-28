#ifndef CATCH_UP_ENGINE_INCLUDE_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_OBJECT_H

#include <string>
#include <vector>
#include "application.h"

namespace Engine
{
	class ScriptBehaviour;
	class SDL_Renderer;
	class Object
	{
		inline static int m_id = 0;
		
		enum class ObjectType;
	protected:
		Object();
		Object(ObjectType type);

		int id;
		ObjectType type;
		std::string name;

		inline virtual std::string toString() const { return name; }
		inline virtual int getInstanceID() const  { return id; }
		inline virtual ObjectType getInstanceType() const { return type; }

		static void destroy(Object* object);

		enum class ObjectType {
			Unknown = 0,
			Object = 1,
			Component = 2,
			GameObject = 3
		};

		virtual ~Object();
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_OBJECT_H