#include "components\vector4f.h"
#include <corecrt_math.h>

Engine::Vector4f::Vector4f() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Engine::Vector4f::Vector4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Engine::Vector4f::Vector4f(const Vector4f& vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.z)
{
}

Engine::Vector4f Engine::Vector4f::operator+(const float number)
{
	return Vector4f(x + number, y + number, z + number, w + number);
}

Engine::Vector4f Engine::Vector4f::operator+(const Vector4f& vector)
{
	return Vector4f(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

Engine::Vector4f Engine::Vector4f::operator-(const float number)
{
	return Vector4f(x - number, y - number, z - number, w - number);
}

Engine::Vector4f Engine::Vector4f::operator-(const Vector4f& vector)
{
	return Vector4f(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

Engine::Vector4f Engine::Vector4f::operator*(const float number)
{
	return Vector4f(x * number, y * number, z * number, w * number);
}

Engine::Vector4f Engine::Vector4f::operator*(const Vector4f& vector)
{
	return Vector4f(x * vector.x, y * vector.y, z * vector.z, w * vector.w);
}

Engine::Vector4f Engine::Vector4f::operator/(const float number)
{
	return Vector4f(x / number, y / number, z / number, w / number);
}

Engine::Vector4f Engine::Vector4f::operator/(const Vector4f& vector)
{
	return Vector4f(x / vector.x, y / vector.y, z / vector.z, w / vector.w);
}

void Engine::Vector4f::operator=(const Vector4f& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
}

bool Engine::Vector4f::operator==(const Vector4f& vector)
{
	return (x == vector.x && y == vector.y && z == vector.z && w == vector.w);
}

Engine::Vector4f Engine::Vector4f::normalized() const
{
	return Vector4f(x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude());
}

float Engine::Vector4f::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z , 2) + pow(w, 2));
}
