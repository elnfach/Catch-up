#include <iostream>
#include "application.h"
#include "game_object.h"

class CatchUp : public Engine::Application
{
public:
	CatchUp();
	~CatchUp();

	void update() override;
};

CatchUp::CatchUp()
{

}

CatchUp::~CatchUp()
{
}

void CatchUp::update()
{

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