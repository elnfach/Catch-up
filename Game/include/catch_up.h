#pragma once

#include "wolf/Wolf.h"
#include "hare/hare.h"
#include "wall/wall.h"

namespace Game
{
	class CatchUp : public Engine::Application
	{
		Wall* top_wall = nullptr;
		Wall* bottom_wall = nullptr;
		Wall* left_wall = nullptr;
		Wall* right_wall = nullptr;
	public:
		CatchUp();
		~CatchUp();
	};
}