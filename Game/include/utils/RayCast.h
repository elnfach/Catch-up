#pragma once

#include <utility>
#include <math.h>
#include <list>
#include <iostream>

#include "entity\entity_type.h"
#include <vector>

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

class RayCast
{
	float m_x;
	float m_y;

	std::vector<float> list_of_rays;
	
	BoxCollider* collider = new BoxCollider("ray", Engine::Vector2f(m_x, m_y), Engine::Vector2f(m_x + 1, m_y + 1));

	EntityType type;

public:
	RayCast();
	~RayCast();

	std::vector<float> cast()
	{
		for (size_t i = 0; i < 37; i++)
		{
			float degrees = (static_cast<float>(i) * 10) * M_PIl / 360.0f;

			/*while (collider->is_collided())
			{
				m_x += cos(degrees);
				m_y += sin(degrees);
				collider->update(vec2((double)m_x, (double)m_y), vec2((int)(m_x + 1), (int)(m_y + 1)));
			}*/
			list_of_rays.push_back(degrees);
		}
		return list_of_rays;
	}
private:

};

RayCast::RayCast()
{
	m_x = 0;
	m_y = 0;
	type = EntityType::UNKNOWN;
}

RayCast::~RayCast()
{
}