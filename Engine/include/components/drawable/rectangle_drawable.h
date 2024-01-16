#ifndef CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H
#define CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H

#include "component.h"
#include "components\vector4f.h"
#include "components\vector2f.h"

namespace Engine
{
	class RectangleDrawable : public Component
	{
	public:
		RectangleDrawable();
		~RectangleDrawable();

		inline std::string toString() const override { return name; }
		inline int getInstanceID() const override { return id; }

		Vector4f color;
		Vector2f size;
	};
}

#endif // !CATCHUP_ENGINE_INCLUDE_COMPONENTS_RECTANGLE_DRAWABLE_H