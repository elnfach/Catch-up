#include <iostream>
#include "application.h"
#include "wolf/Wolf.h"
#include <components\transform.h>
#include <hare/hare.h>
#include <wall/wall.h>

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

CatchUp::CatchUp()
{
	std::cout << "Catch up!\n";
	std::cout << "Version: 0.1a\n";
}

CatchUp::~CatchUp()
{
	delete wolf;
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

Engine::Application* createApplication()
{
	return new CatchUp();
}

int main()
{
	setlocale(0, "");
	auto app = createApplication();
	app->run();
	delete app;
}