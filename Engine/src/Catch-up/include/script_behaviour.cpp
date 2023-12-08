#include <iostream>
#include "script_behaviour.h"
#include "game_object.h"
#include "scene.h"

Engine::ScriptBehaviour* Engine::ScriptBehaviour::m_ptr_instance = nullptr;

Engine::ScriptBehaviour::ScriptBehaviour() : GameObject()
{
}

Engine::ScriptBehaviour::~ScriptBehaviour()
{
}