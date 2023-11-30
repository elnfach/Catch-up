#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include <functional>
#include "components/transform.h"
#include <components/drawable/drawable.h>

namespace Engine
{
	class GameObject : public Object
	{
	public:
		GameObject();
		~GameObject();

		Drawable* drawable;
		Transform* transform;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H