#include <iostream>
#include "application.h"
#include "entity/Wolf.h"
#include <components\transform.h>

class CatchUp : public Engine::Application
{
	Wolf* wolf;
	Wolf* wolf1;
public:
	CatchUp();
	~CatchUp();

	void update() override;
};

CatchUp::CatchUp()
{
	wolf = new Wolf(100, 0, 25, 25);
	wolf1 = new Wolf(100, 0, 25, 25);
}

CatchUp::~CatchUp()
{
	delete wolf;
}
float x;
float y;
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