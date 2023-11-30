#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H

#include "drawable.h"

namespace Engine
{
	class RectangleDrawable : public Drawable
	{
	public:
		RectangleDrawable();
		RectangleDrawable(Vector2f position, Vector2f end);
		RectangleDrawable(Transform* transform);
		~RectangleDrawable();

		Drawable* draw() override;
	private:

	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H