#pragma once
#include "components/vector2f.h"
#include <vector>

namespace Game
{
	class Map
	{
		Map();
	public:
		Map(const Map&) = delete;
		Map(const Map&&) = delete;
		~Map();
		void operator=(Map&) = delete;

		static Map* getInstance();

		std::vector<Engine::Vector2f> generateRandomMap(Engine::Vector2f start, Engine::Vector2f end, uint32_t count, double radius);
	private:
		static Map* s_ptr_instance;
	};
}