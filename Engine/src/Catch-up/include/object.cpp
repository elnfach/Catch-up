#include "object.h"
#include "SDL.h"
#include "script_behaviour.h"

Engine::Object::Object()
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	type = ObjectType::Object;
}

Engine::Object::Object(ObjectType type)
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	this->type = type;
}

void Engine::Object::destroy(Object* object)
{
	m_id -= 1;
	
	delete object;
}

Engine::Object::~Object()
{

}
