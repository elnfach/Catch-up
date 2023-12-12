#include "catch_up.h"
#include <iostream>

CatchUp::CatchUp()
{
	std::cout << "Catch up!\n";
	std::cout << "Version: 0.1a\n";
}

CatchUp::~CatchUp()
{
	delete wolf;
	delete hare;
	delete top_wall;
	delete bottom_wall;
	delete left_wall;
	delete right_wall;
}

void CatchUp::start()
{
	wolf = new Wolf(100, 100, 25, 25);
	hare = new Hare(100, 500, 25, 25);

	top_wall = new Wall(640, 0, 1280, 10);
	bottom_wall = new Wall(640, 720, 1280, 10);
	left_wall = new Wall(0, 360, 10, 710);
	right_wall = new Wall(1270, 360, 10, 710);
}

void CatchUp::update()
{
	wolf->move(Engine::Vector2f(0, 1.0f));
}