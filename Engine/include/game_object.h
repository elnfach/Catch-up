#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include <functional>
#include "components/transform.h"
#include <components/drawable/rectangle_drawable.h>

namespace Engine
{
	class GameObject : public Object
	{
	public:
		GameObject();
		~GameObject();

		Transform* transform;
		RectangleDrawable* drawable;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H