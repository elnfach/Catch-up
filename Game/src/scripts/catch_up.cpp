#include "catch_up.h"
#include "components/transform.h"
#include <iostream>
#include "random.h"

std::vector<Wolf*> Game::CatchUp::m_wolf_list;
std::vector<Hare*> Game::CatchUp::m_hare_list;

Game::CatchUp::CatchUp()
{
	std::cout << "Catch up!\n";
	std::cout << "Version: 0.1a\n";
}

Game::CatchUp::~CatchUp()
{
	delete wolf;
	delete top_wall;
	delete bottom_wall;
	delete left_wall;
	delete right_wall;
}

void Game::CatchUp::start()
{
	wolf = new Wolf(100, 100, 25, 25);
	hare = new Hare(100, 500, 25, 25);

	top_wall = new Wall(640, 0, 1280, 10);
	bottom_wall = new Wall(640, 720, 1280, 10);
	left_wall = new Wall(0, 360, 10, 710);
	right_wall = new Wall(1270, 360, 10, 710);

	m_wolf_list.push_back(wolf);
	m_hare_list.push_back(hare);
}

void Game::CatchUp::update()
{
	for (auto& i : m_wolf_list)
	{
		i->move(Engine::Vector2f(0, 1.0f), hare->getComponent<Engine::Transform>().position);
	}
	for (auto& i : m_hare_list)
	{
		i->move(Engine::Vector2f(0, 1.0f), Engine::Vector2f()); // target is carrot;
	}
}