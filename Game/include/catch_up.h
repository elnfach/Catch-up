#pragma once

#include "wolf/Wolf.h"
#include "hare/hare.h"
#include "wall/wall.h"

class CatchUp : public Engine::Application
{
	Wolf* wolf = nullptr;
	Hare* hare = nullptr;
	Wall* top_wall = nullptr;
	Wall* bottom_wall = nullptr;
	Wall* left_wall = nullptr;
	Wall* right_wall = nullptr;
public:
	CatchUp();
	~CatchUp();

	void start() override;
	void update() override;
};