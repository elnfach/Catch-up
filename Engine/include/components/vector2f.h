#ifndef CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H
#define CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H

class Vector2f
{
	float m_x;
	float m_y;
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
	bool operator==(const Vector2f& vector);

	Vector2f normalized();
	float magnitude();
};

#endif // !CATCH_UP_ENGINE_INCLUDE_COMPONENTS_VECTOR_2F_H