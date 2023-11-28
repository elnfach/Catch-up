#include "object.h"

Engine::Object::Object()
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	type = ObjectType::Object;

	objects.push_back(this);
}

Engine::Object::Object(ObjectType type)
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	this->type = type;
	objects.push_back(this);
}

void Engine::Object::update()
{
	draw();
}

void Engine::Object::destroy(Object* object)
{
	m_id -= 1;
	
	delete object;
}

Engine::Object::~Object()
{

}
