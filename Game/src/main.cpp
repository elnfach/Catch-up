#include <iostream>
#include "application.h"
#include "wolf/Wolf.h"
#include <components\transform.h>

class CatchUp : public Engine::Application
{
	Wolf* wolf = nullptr;
	Wolf* wolf1 = nullptr;
public:
	CatchUp();
	~CatchUp();

	void start() override;
	void update() override;
};

CatchUp::CatchUp()
{
}

CatchUp::~CatchUp()
{
	delete wolf;
}
float x;
float y;
void CatchUp::start()
{
	wolf = new Wolf(100, 650, 25, 25);
	wolf1 = new Wolf(100, 625, 25, 25);
}
void CatchUp::update()
{
	y += 0.1f;
	wolf->move(100, y);
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