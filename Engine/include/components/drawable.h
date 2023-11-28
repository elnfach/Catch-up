#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H

#include "transform.h"

namespace Engine
{
	class Drawable final : public Component
	{
		
	public:
		Drawable();
		~Drawable();

		Transform transform;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H