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

Engine::Vector2f::Vector2f() : x(0.0f), y(0.0f)
{
}

Engine::Vector2f::Vector2f(float x, float y) : x(x), y(y)
{
}

Engine::Vector2f::Vector2f(const Vector2f& vector) : x(vector.x), y (vector.y)
{
}

Engine::Vector2f Engine::Vector2f::operator+(const float number)
{
	return Vector2f(x + number, y + number);
}

Engine::Vector2f Engine::Vector2f::operator+(const Vector2f& vector)
{
	return Vector2f(x + vector.x, y + vector.y);
}

Engine::Vector2f Engine::Vector2f::operator-(const float number)
{
	return Vector2f(x - number, y - number);
}

Engine::Vector2f Engine::Vector2f::operator-(const Vector2f& vector)
{
	return Vector2f(x - vector.x, y - vector.y);
}

Engine::Vector2f Engine::Vector2f::operator*(float number)
{
	return Vector2f(x * number, y * number);
}

Engine::Vector2f Engine::Vector2f::operator*(const Vector2f& vector)
{
	return Vector2f(x * vector.x, y * vector.y);
}

Engine::Vector2f Engine::Vector2f::operator/(const float number)
{
	return Vector2f(x / number, y / number);
}

Engine::Vector2f Engine::Vector2f::operator/(const Vector2f& vector)
{
	return Vector2f(x / vector.x, y / vector.y);
}

void Engine::Vector2f::operator=(const Vector2f& vector)
{
	x = vector.x;
	y = vector.y;
}

bool Engine::Vector2f::operator==(const Vector2f& vector)
{
	return (x == vector.x && y == vector.y);
}