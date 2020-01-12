#pragma once

#include <cstdint>

template<typename T>
class Vector2D
{
public:
	static constexpr Vector2D<T> Zero()
	{ return Vector2D<T>{0, 0}; }

	static constexpr Vector2D<T> Unit()
	{ return Vector2D<T>{1, 1}; }

public:
	T X, Y;

	constexpr Vector2D(T x, T y) : X(x), Y(y)
	{}

	Vector2D operator+(const Vector2D &right) const
	{
		return Vector2D(X + right.X, Y + right.Y);
	}

	Vector2D operator-(const Vector2D &right) const
	{
		return Vector2D(X - right.X, Y - right.Y);
	}
};

using Vector2DUint16 = Vector2D<uint16_t>;
