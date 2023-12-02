#include <iostream>
#include "script_behaviour.h"
#include "game_object.h"

Engine::ScriptBehaviour* Engine::ScriptBehaviour::m_ptr_instance = nullptr;

Engine::ScriptBehaviour::ScriptBehaviour() : GameObject()
{
	std::cout << "Hello\n";	
}

Engine::ScriptBehaviour::~ScriptBehaviour()
{
}