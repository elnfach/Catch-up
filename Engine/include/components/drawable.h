#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H

#include "transform.h"

struct SDL_FRect;
namespace Engine
{
	enum class DrawableType
	{

	};

	
	class Drawable final
	{
	public:
		Drawable();
		Drawable(Transform* transform);
		~Drawable();

		::SDL_FRect* rect;

		Transform* transform;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H