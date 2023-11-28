#include <cmath>
#include "components/vector2f.h"

float Engine::Vector2f::magnitude()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

Engine::Vector2f Engine::Vector2f::normalized()
{
	return Vector2f(pow(m_x / magnitude(), 2) + pow(m_y / magnitude(), 2), 0);
}

Engine::Vector2f::Vector2f()
{
	m_x = 1;
	m_y = 0;
}

Engine::Vector2f::Vector2f(float x, float y)
{
	m_x = x;
	m_y = y;
}

Engine::Vector2f::Vector2f(const Vector2f& vector)
{
	m_x = vector.m_x;
	m_y = vector.m_y;
}

Engine::Vector2f Engine::Vector2f::operator+(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x + number, temp.m_y + number);
}

Engine::Vector2f Engine::Vector2f::operator+(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x + vector.m_x, temp.m_y + vector.m_y);
}

Engine::Vector2f Engine::Vector2f::operator-(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x - number, temp.m_y - number);
}

Engine::Vector2f Engine::Vector2f::operator-(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x - vector.m_x, temp.m_y - vector.m_y);
}

Engine::Vector2f Engine::Vector2f::operator*(float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x * number, temp.m_y * number);
}

Engine::Vector2f Engine::Vector2f::operator*(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x * vector.m_x, temp.m_y * vector.m_y);
}

Engine::Vector2f Engine::Vector2f::operator/(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x / number, temp.m_y / number);
}

Engine::Vector2f Engine::Vector2f::operator/(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.m_x / vector.m_x, temp.m_y / vector.m_y);
}

void Engine::Vector2f::operator=(const Vector2f& vector)
{
	m_x = vector.m_x;
	m_y = vector.m_y;
}

bool Engine::Vector2f::operator==(const Vector2f& vector)
{
	if (m_x == vector.m_x && m_y == vector.m_y)
	{
		return true;
	}
	return false;
}