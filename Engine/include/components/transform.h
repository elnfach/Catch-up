#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H

#include "component.h"
#include "vector2f.h"

class Transform final : public Component
{
	Vector2f m_locale_position;
public:
	Transform();
	~Transform();
};

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENTS_TRANSFORM_H