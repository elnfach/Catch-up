#include "application.h"
#include "catch_up.h"
#include <locale.h>


static Engine::Application* createApplication()
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