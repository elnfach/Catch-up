#pragma once

class Application;
class Core
{
public:
	Core();
	virtual ~Core() {}
};

Core* start();