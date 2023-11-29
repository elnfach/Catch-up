#pragma once

#include <string>
#include "components/vector2f.h"

class BoxCollider
{
	std::string m_name;

	Engine::Vector2f m_start;
	Engine::Vector2f m_end;
public:
	
	BoxCollider() = delete;
	BoxCollider(std::string name, Engine::Vector2f start, Engine::Vector2f end)
	{
		m_name = name;
		m_start = start;
		m_end = end;
	}

	void update(Engine::Vector2f start, Engine::Vector2f end)
	{
		m_start = start;
		m_end = end;
	}

	bool is_collided(BoxCollider* collider)
	{
		if (strcmp(m_name.c_str(), collider->m_name.c_str()) == 0)
		{
			return false;
		}

		if (m_start.x <= collider->m_start.x && collider->m_start.x <= m_end.x)
		{
			if (m_start.y <= collider->m_start.y && collider->m_start.y <= m_end.y)
			{
				return true;
			}
			if (m_start.y <= collider->m_end.y && collider->m_end.y <= m_end.y)
			{
				return true;
			}
		}
		else if (m_start.x <= collider->m_end.x && collider->m_end.x <= m_end.x)
		{
			if (m_start.y <= collider->m_start.y && collider->m_start.y <= m_end.y)
			{
				return true;
			}
			if (m_start.y <= collider->m_end.y && collider->m_end.y <= m_end.y)
			{
				return true;
			}
		}
		return false;
	}
};