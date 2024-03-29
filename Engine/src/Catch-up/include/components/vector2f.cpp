#include <cmath>
#include "components/vector2f.h"

float Engine::Vector2f::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Engine::Vector2f Engine::Vector2f::normalized() const
{
	return Vector2f(x / magnitude(), y / magnitude());
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

void Engine::Vector2f::operator+=(const Vector2f& vector)
{
	x = x + vector.x;
	y = y + vector.y;
}

void Engine::Vector2f::operator+=(const float number)
{
	x = x + number;
	y = y + number;
}

void Engine::Vector2f::operator-=(const Vector2f& vector)
{
	x = x - vector.x;
	y = y - vector.y;
}

void Engine::Vector2f::operator-=(const float number)
{
	x = x - number;
	y = y - number;
}

void Engine::Vector2f::operator*=(const Vector2f& vector)
{
	x = x * vector.x;
	y = y * vector.y;
}

void Engine::Vector2f::operator*=(const float number)
{
	x = x * number;
	y = y * number;
}

void Engine::Vector2f::operator/=(const Vector2f& vector)
{
	x = x / vector.x;
	y = y / vector.y;
}

void Engine::Vector2f::operator/=(const float number)
{
	x = x / number;
	y = y / number;
}

bool Engine::Vector2f::operator==(const Vector2f& vector)
{
	return (x == vector.x && y == vector.y);
}