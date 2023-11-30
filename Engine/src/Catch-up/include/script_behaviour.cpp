#include "script_behaviour.h"
#include <iostream>

Engine::ScriptBehaviour* Engine::ScriptBehaviour::m_ptr_instance = nullptr;

Engine::ScriptBehaviour::ScriptBehaviour() : Component(ComponentType::ScriptBehaviour)
{
	std::cout << "Hello\n";
}

Engine::ScriptBehaviour::~ScriptBehaviour()
{
}
