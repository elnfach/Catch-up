#include "components\vector3f.h"
#include <corecrt_math.h>

Engine::Vector3f::Vector3f() : x(0.0f), y(0.0f), z(0.0f)
{
}

Engine::Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z)
{
}

Engine::Vector3f::Vector3f(const Vector3f& vector) : x(vector.x), y(vector.y), z(vector.z)
{
}

Engine::Vector3f Engine::Vector3f::operator+(const float number)
{
	return Vector3f(x + number, y + number, z + number);
}

Engine::Vector3f Engine::Vector3f::operator+(const Vector3f& vector)
{
	return Vector3f(x + vector.x, y + vector.y, z + vector.z);
}

Engine::Vector3f Engine::Vector3f::operator-(const float number)
{
	return Vector3f(x - number, y - number, z - number);
}

Engine::Vector3f Engine::Vector3f::operator-(const Vector3f& vector)
{
	return Vector3f(x - vector.x, y - vector.y, z - vector.z);
}

Engine::Vector3f Engine::Vector3f::operator*(const float number)
{
	return Vector3f(x * number, y * number, z * number);
}

Engine::Vector3f Engine::Vector3f::operator*(const Vector3f& vector)
{
	return Vector3f(x * vector.x, y * vector.y, z * vector.z);
}

Engine::Vector3f Engine::Vector3f::operator/(const float number)
{
	return Vector3f(x / number, y / number, z / number);
}

Engine::Vector3f Engine::Vector3f::operator/(const Vector3f& vector)
{
	return Vector3f(x / vector.x, y / vector.y, z / vector.z);
}

void Engine::Vector3f::operator=(const Vector3f& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

void Engine::Vector3f::operator+=(const Vector3f& vector)
{
	x = x + vector.x;
	y = y + vector.y;
	z = z + vector.z;
}

void Engine::Vector3f::operator+=(const float number)
{
	x = x + number;
	y = y + number;
	z = z + number;
}

void Engine::Vector3f::operator-=(const Vector3f& vector)
{
	x = x - vector.x;
	y = y - vector.y;
	z = z - vector.z;
}

void Engine::Vector3f::operator-=(const float number)
{
	x = x - number;
	y = y - number;
	z = z - number;
}

void Engine::Vector3f::operator*=(const Vector3f& vector)
{
	x = x * vector.x;
	y = y * vector.y;
	z = z * vector.z;
}

void Engine::Vector3f::operator*=(const float number)
{
	x = x * number;
	y = y * number;
	z = z * number;
}

void Engine::Vector3f::operator/=(const Vector3f& vector)
{
	x = x / vector.x;
	y = y / vector.y;
	z = z / vector.z;
}

void Engine::Vector3f::operator/=(const float number)
{
	x = x / number;
	y = y / number;
	z = z / number;
}

bool Engine::Vector3f::operator==(const Vector3f& vector)
{
	return (x == vector.x && y == vector.y && z == vector.z);
}

Engine::Vector3f Engine::Vector3f::normalized() const
{
	return Vector3f(x / magnitude(), y / magnitude(), z / magnitude());
}

float Engine::Vector3f::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z , 2));
}
