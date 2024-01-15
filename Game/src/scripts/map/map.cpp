#include "map/map.h"

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

std::list<Engine::Vector2f> Game::Map::generateRandomMap(Engine::Vector2f start, Engine::Vector2f end)
{
	return std::list<Engine::Vector2f>();
}
