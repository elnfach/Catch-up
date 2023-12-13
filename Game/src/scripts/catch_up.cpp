#include "catch_up.h"
#include "components/transform.h"
#include <iostream>
#include "random.h"
#include "event/event_manager.h"

Game::CatchUp::CatchUp()
{
	std::cout << "Catch up!\n";
	std::cout << "Version: 0.1a\n";

	top_wall = new Wall(640, 0, 1280, 10);
	bottom_wall = new Wall(640, 720, 1280, 10);
	left_wall = new Wall(0, 360, 10, 710);
	right_wall = new Wall(1270, 360, 10, 710);

	EventManager::getInstance()->setNumberOfWolfAndSize(1);
	EventManager::getInstance()->setNumberOfHareAndSize(1);
	EventManager::getInstance()->spawn(Engine::Vector2f(25, 25), Engine::Vector2f(1240, 690));
}

Game::CatchUp::~CatchUp()
{
	EventManager::terminate();
}