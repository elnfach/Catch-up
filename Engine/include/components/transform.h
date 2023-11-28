#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H

#include "component.h"
#include "vector2f.h"

namespace Engine
{
	class Transform final : public Component
	{
	public:
		Transform();
		~Transform();

		inline std::string toString() const override { return name; }
		inline int getInstanceID() const override  { return id; }
		inline ObjectType getInstanceType() const override  { return type; }

		void translate(Vector2f translation);

		Vector2f m_locale_position;
		Vector2f position;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H