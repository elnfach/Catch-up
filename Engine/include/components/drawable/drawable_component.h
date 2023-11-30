#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H

#include "components\transform_component.h"

struct SDL_FRect;
namespace Engine
{
	enum class DrawableType
	{

	};

	class DrawableComponent : public Component
	{
	public:
		DrawableComponent();
		DrawableComponent(Vector2f position, Vector2f end);
		DrawableComponent(TransformComponent* transform);
		~DrawableComponent();

		::SDL_FRect* rect;
		TransformComponent* transform;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_DRAWABLE_H