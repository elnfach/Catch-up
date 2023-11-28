#pragma once
#include <string>
#include <utility>

namespace Engine
{
	typedef std::pair<double, double> vec2;
#define vec2(first, second) std::make_pair<double, double>(first, second)

	class Collider
	{
	protected:
		std::string name;

		vec2 m_start;
		vec2 m_end;

		virtual void update() = 0;
		virtual bool is_collided(Collider* collider) = 0;
	public:
		Collider();
		~Collider();
	};
}