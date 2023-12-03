#include "components/colliders/box_collider.h"

Engine::BoxCollider::BoxCollider() : offset(Vector2f(0, 0)), size(Vector2f(0.5f, 0.5f))
{
}

Engine::BoxCollider::~BoxCollider()
{
}
