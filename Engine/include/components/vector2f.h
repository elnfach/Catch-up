#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H

namespace Engine
{
	class Vector2f
	{
	public:
		Vector2f();
		Vector2f(float x, float y);
		Vector2f(const Vector2f& vector);
		~Vector2f() {}

		Vector2f operator+(const float number);
		Vector2f operator+(const Vector2f& vector);

		Vector2f operator-(const float number);
		Vector2f operator-(const Vector2f& vector);

		Vector2f operator*(const float number);
		Vector2f operator*(const Vector2f& vector);

		Vector2f operator/(const float number);
		Vector2f operator/(const Vector2f& vector);

		void operator=(const Vector2f& vector);

		void operator+=(const Vector2f& vector);
		void operator+=(const float number);
		void operator-=(const Vector2f& vector);
		void operator-=(const float number);
		void operator*=(const Vector2f& vector);
		void operator*=(const float number);
		void operator/=(const Vector2f& vector);
		void operator/=(const float number);

		bool operator==(const Vector2f& vector);

		Vector2f normalized() const;
		float magnitude() const;

		float x;
		float y;
	};
}

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H