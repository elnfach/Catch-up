#pragma once

namespace Engine
{
	class Vector4f
	{
	public:
		Vector4f();
		Vector4f(float x, float y, float z, float w);
		Vector4f(const Vector4f& vector);
		~Vector4f() {}

		Vector4f operator+(const float number);
		Vector4f operator+(const Vector4f& vector);

		Vector4f operator-(const float number);
		Vector4f operator-(const Vector4f& vector);

		Vector4f operator*(const float number);
		Vector4f operator*(const Vector4f& vector);

		Vector4f operator/(const float number);
		Vector4f operator/(const Vector4f& vector);

		void operator=(const Vector4f& vector);
		bool operator==(const Vector4f& vector);

		Vector4f normalized();
		float magnitude();

		float x;
		float y;
		float z;
		float w;
	};
}