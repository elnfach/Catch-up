#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H

#include "component.h"
#include "components\transform.h"
#include <functional>

struct SDL_FRect;
namespace Engine
{
	enum class DrawableType
	{

	};

	class Drawable : public Component
	{
	protected:
		Drawable();
		Drawable(Vector2f position, Vector2f end);
		Drawable(Transform* transform);

		

		virtual ~Drawable();
	public:
		void update() override;
		virtual Drawable* draw() = 0;
		::SDL_FRect* rect;
		Transform* transform;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H