#include "object.h"

Object::Object()
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	type = ObjectType::Object;

	objects.push_back(this);
}

Object::Object(ObjectType type)
{
	name = "Default object name";
	m_id += 1;
	id = m_id;
	this->type = type;
	objects.push_back(this);
}

void Object::update()
{
	draw();
}

void Object::destroy(Object* object)
{
	m_id -= 1;
	
	delete object;
}

Object::~Object()
{

}
