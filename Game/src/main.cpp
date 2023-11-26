#include <iostream>
#include "application.h"

class CatchUp : public Application
{
public:
	CatchUp();
	~CatchUp();
};

CatchUp::CatchUp()
{
	std::cout << "Hello world!";
}

CatchUp::~CatchUp()
{
}

Application* createApplication()
{
	return new CatchUp();
}

int WinMain()
{
	auto app = createApplication();
	app->run();
	delete app;
}