#include <iostream>
#include "application.h"
#include "wolf/Wolf.h"
#include <components\transform.h>
#include <hare/hare.h>

class CatchUp : public Engine::Application
{
	Wolf* wolf = nullptr;
	Hare* hare = nullptr;
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
	wolf = new Wolf(100, 0, 25, 25);
	hare = new Hare(100, 500, 25, 25);
}
void CatchUp::update()
{
	wolf->move(Engine::Vector2f(0, 0.1f));
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