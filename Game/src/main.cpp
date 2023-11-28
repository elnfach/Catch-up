#include <iostream>
#include "application.h"
#include "game_object.h"
#include "script_behaviour.h"
#include "components/drawable.h"

class MyClass : public Engine::ScriptBehaviour
{
public:
	void start() override
	{
		std::cout << "My class";
	}

	void update() override
	{

	}
	
};
class CatchUp : public Engine::Application
{
	Engine::Drawable* drawable;
public:
	CatchUp();
	~CatchUp();

	void update() override;
	Engine::Drawable* draw() override
	{
		return drawable;
	}
};

CatchUp::CatchUp()
{
	drawable = new Engine::Drawable();
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