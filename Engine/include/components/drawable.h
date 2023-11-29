#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H

#include "transform.h"

struct SDL_FRect;
namespace Engine
{
	enum class DrawableType
	{

	};

	class GameObject;
	class Drawable : public Component
	{
	public:
		Drawable();
		Drawable(Vector2f position, Vector2f end);
		Drawable(Transform* transform);
		~Drawable();

		void update();

		::SDL_FRect* rect;

		Transform* transform;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H