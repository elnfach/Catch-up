#include <iostream>
#include "application.h"
#include "game_object.h"
#include "script_behaviour.h"
#include "components/drawable/drawable.h"

#include "entity/Wolf.h"

class MyClass : public Engine::ScriptBehaviour
{
public:
	void start() override
	{
		
	}

	void update() override
	{

	}
	
};
class CatchUp : public Engine::Application
{
	Wolf* wolf;
	Wolf* wolf2;
	Wolf* wolf3;
public:
	CatchUp();
	~CatchUp();

	void update() override;
};

CatchUp::CatchUp()
{
	std::cout << "My class\n";
	wolf = new Wolf();
	wolf2 = new Wolf(100, 100, 25, 25);
	wolf3 = new Wolf(200, 100, 25, 25);
}

CatchUp::~CatchUp()
{
	delete wolf;
	delete wolf2;
	delete wolf3;
}

void CatchUp::update()
{
	//wolf->update();
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