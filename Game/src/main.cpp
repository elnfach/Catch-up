#include <iostream>
#include "application.h"
#include "entity/Wolf.h"
#include <components\transform.h>

class CatchUp : public Engine::Application
{
	Wolf* wolf;
public:
	CatchUp();
	~CatchUp();

	void update() override;
};

CatchUp::CatchUp()
{
	wolf = new Wolf(100, 0, 100, 100);
}

CatchUp::~CatchUp()
{
	delete wolf;
}
float x;
void CatchUp::update()
{
	x += 0.1f;
	wolf->move(x, 0);
}

Engine::Application* createApplication()
{
	return new CatchUp();
}

int main()
{
	auto app = createApplication();
	app->run();
	delete app;
}