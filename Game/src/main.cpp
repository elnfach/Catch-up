#include <iostream>
#include "application.h"
#include "game_object.h"
#include "script_behaviour.h"
#include "components/drawable.h"

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
	Engine::Drawable* drawable;
public:
	CatchUp();
	~CatchUp();

	void update() override;
	Engine::Drawable* draw() override
	{
		return wolf->drawable;
	}
};

CatchUp::CatchUp()
{
	std::cout << "My class\n";
	drawable = new Engine::Drawable();
	wolf = new Wolf();
}

CatchUp::~CatchUp()
{
	
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