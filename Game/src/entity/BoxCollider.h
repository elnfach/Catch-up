#pragma once

#include <string>
#include "core.h"

class BoxCollider
{
	std::string m_name;

	vec2 m_start;
	vec2 m_end;
public:
	
	BoxCollider() = delete;
	BoxCollider(std::string name, vec2 start, vec2 end)
	{
		m_name = name;
		m_start = start;
		m_end = end;
	}

	void update(vec2 start, vec2 end)
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

		if (m_start.first <= collider->m_start.first && collider->m_start.first <= m_end.first)
		{
			if (m_start.second <= collider->m_start.second && collider->m_start.second <= m_end.second)
			{
				return true;
			}
			if (m_start.second <= collider->m_end.second && collider->m_end.second <= m_end.second)
			{
				return true;
			}
		}
		else if (m_start.first <= collider->m_end.first && collider->m_end.first <= m_end.first)
		{
			if (m_start.second <= collider->m_start.second && collider->m_start.second <= m_end.second)
			{
				return true;
			}
			if (m_start.second <= collider->m_end.second && collider->m_end.second <= m_end.second)
			{
				return true;
			}
		}
		return false;
	}
};