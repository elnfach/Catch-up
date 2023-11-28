#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENT_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENT_H

#include "object.h"

namespace Engine
{
	class Component : public Object
	{
	private:
		void draw() {

		}
	protected:

	public:
		Component();
		Component(ObjectType type);
		~Component();
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENT_H