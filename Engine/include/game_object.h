#ifndef CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H
#define CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H

#include "object.h"
#include <functional>

namespace Engine
{
	class GameObject : public Object
	{
	private:
		void draw() override;
	public:
		GameObject();
		~GameObject();
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_GAME_OBJECT_H