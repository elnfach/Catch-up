#include <cmath>
#include "components/vector2f.h"

float Engine::Vector2f::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Engine::Vector2f Engine::Vector2f::normalized()
{
	return Vector2f(pow(x / magnitude(), 2) + pow(y / magnitude(), 2), 0);
}

Engine::Vector2f::Vector2f()
{
	x = 1;
	y = 0;
}

Engine::Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Engine::Vector2f::Vector2f(const Vector2f& vector)
{
	x = vector.x;
	y = vector.y;
}

Engine::Vector2f Engine::Vector2f::operator+(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.x + number, temp.y + number);
}

Engine::Vector2f Engine::Vector2f::operator+(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.x + vector.x, temp.y + vector.y);
}

Engine::Vector2f Engine::Vector2f::operator-(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.x - number, temp.y - number);
}

Engine::Vector2f Engine::Vector2f::operator-(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.x - vector.x, temp.y - vector.y);
}

Engine::Vector2f Engine::Vector2f::operator*(float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.x * number, temp.y * number);
}

Engine::Vector2f Engine::Vector2f::operator*(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.x * vector.x, temp.y * vector.y);
}

Engine::Vector2f Engine::Vector2f::operator/(const float number)
{
	Vector2f temp = *this;
	return Vector2f(temp.x / number, temp.y / number);
}

Engine::Vector2f Engine::Vector2f::operator/(const Vector2f& vector)
{
	Vector2f temp = *this;
	return Vector2f(temp.x / vector.x, temp.y / vector.y);
}

void Engine::Vector2f::operator=(const Vector2f& vector)
{
	x = vector.x;
	y = vector.y;
}

bool Engine::Vector2f::operator==(const Vector2f& vector)
{
	if (x == vector.x && y == vector.y)
	{
		return true;
	}
	return false;
}