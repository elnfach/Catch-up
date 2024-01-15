#pragma once
#include "components/vector2f.h"
#include <list>

namespace Game
{
	class Map
	{
		Map();
		~Map();
	public:
		Map(const Map&) = delete;
		Map(const Map&&) = delete;

		void operator=(Map&) = delete;

		static Map* getInstance();

		std::list<Engine::Vector2f> generateRandomMap(Engine::Vector2f start, Engine::Vector2f end);
	private:
		static Map* s_ptr_instance;
	};
}