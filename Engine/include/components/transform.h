#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H

#include "component.h"
#include "vector2f.h"
#include <string>

namespace Engine
{
	class Transform final : public Component
	{
	public:
		Transform();
		~Transform();

		inline std::string toString() const override { return name; }
		inline int getInstanceID() const override  { return id; }

		void translate(Vector2f translation);

		Vector2f position;
		Vector2f rotation;
		Vector2f scale;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H