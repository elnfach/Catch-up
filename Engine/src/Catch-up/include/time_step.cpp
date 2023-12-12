#include "time_step.h"

float Engine::Timestep::m_time = 0.0f;

Engine::Timestep* Engine::Timestep::getInstance()
{
	Timestep instance;
	return &instance;
}

Engine::Timestep::operator float() const
{
	return m_time;
}

void Engine::Timestep::setDeltaTime(float time)
{
	m_time = time;
}

float Engine::Timestep::getDeltaTime()
{
	return m_time;
}

float Engine::Timestep::getMilliseconds()
{
	return m_time * 1000.0f;
}
