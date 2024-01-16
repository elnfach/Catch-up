#pragma once

namespace Engine
{
	class Vector3f
	{
	public:
		Vector3f();
		Vector3f(float x, float y, float z);
		Vector3f(const Vector3f& vector);
		~Vector3f() {}

		Vector3f operator+(const float number);
		Vector3f operator+(const Vector3f& vector);

		Vector3f operator-(const float number);
		Vector3f operator-(const Vector3f& vector);

		Vector3f operator*(const float number);
		Vector3f operator*(const Vector3f& vector);

		Vector3f operator/(const float number);
		Vector3f operator/(const Vector3f& vector);

		void operator=(const Vector3f& vector);

		void operator+=(const Vector3f& vector);
		void operator+=(const float number);
		void operator-=(const Vector3f& vector);
		void operator-=(const float number);
		void operator*=(const Vector3f& vector);
		void operator*=(const float number);
		void operator/=(const Vector3f& vector);
		void operator/=(const float number);

		bool operator==(const Vector3f& vector);

		Vector3f normalized() const;
		float magnitude() const;

		float x;
		float y;
		float z;
	};
}