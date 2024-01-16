#include "map/map.h"
#include <random.h>

Game::Map* Game::Map::s_ptr_instance = nullptr;

Game::Map::Map()
{
}

Game::Map::~Map()
{
}

Game::Map* Game::Map::getInstance()
{
	if (s_ptr_instance == nullptr)
		s_ptr_instance = new Map();
	return s_ptr_instance;
}

std::vector<Engine::Vector2f> Game::Map::generateRandomMap(Engine::Vector2f start, Engine::Vector2f end, uint32_t count, double radius)
{
	Engine::Random random;
	std::vector<Engine::Vector2f> map;
	
	for (size_t i = 0; i < count; i++)
	{
		int x;
		int y;
		bool flag = true;
		while (flag)
		{
			x = random.Next(start.x, end.x);
			y = random.Next(start.y, end.y);
			if (!map.empty())
			{
				for (auto& i : map)
				{
					if (sqrt(pow(i.x - x, 2) + pow(i.y - y, 2)) > radius);
					{
						map.push_back(Engine::Vector2f(x, y));
						flag = false;
						break;
					}
				}
			}
			else
			{
				map.push_back(Engine::Vector2f(x, y));
			}
		}
	}

	return map;
}
