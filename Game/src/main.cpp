#include "application.h"
#include "components\transform.h"
#include "hare/hare.h"
#include "wall/wall.h"
#include "wolf/Wolf.h"
#include <iostream>

class CatchUp : public Engine::Application
{
	Wolf* wolf = nullptr;
	Hare* hare = nullptr;
	Wall* top_wall = nullptr;
	Wall* bottom_wall = nullptr;
	Wall* left_wall = nullptr;
	Wall* right_wall = nullptr;
	Engine::Transform* hare_pos;
public:
	CatchUp();
	~CatchUp();

	void start() override;
	void update(float deltaTime) override;
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
	hare = new Hare(500, 100, 25, 25);
	hare_pos = &hare->getComponent<Engine::Transform>();

	top_wall = new Wall(640, 0, 1280, 10);
	bottom_wall = new Wall(640, 720, 1280, 10);
	left_wall = new Wall(0, 360, 10, 710);
	right_wall = new Wall(1270, 360, 10, 710);

	auto& box = top_wall->getComponent<Engine::Transform>();
}
void CatchUp::update(float deltaTime)
{
	wolf->move(Engine::Vector2f(0, 1.0f), hare_pos->position, deltaTime);
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