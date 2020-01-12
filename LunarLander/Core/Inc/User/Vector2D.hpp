#pragma once

#include <cstdint>
#include <cmath>

namespace LunarLander
{
	template<typename T>
	class Vector2D
	{
	public:
		static constexpr Vector2D<T> Zero()
		{ return Vector2D<T>{0, 0}; }

		static constexpr Vector2D<T> Unit()
		{ return Vector2D<T>{1, 1}; }

		static constexpr Vector2D<T> Up()
		{ return Vector2D<T>{0, 1}; }

		static constexpr Vector2D<T> Down()
		{ return Vector2D<T>{0, -1}; }

	public:
		T X, Y;

		constexpr Vector2D(T x, T y) : X(x), Y(y)
		{}

		Vector2D operator+(const Vector2D& right) const
		{
			return Vector2D(X + right.X, Y + right.Y);
		}

		void operator+=(const Vector2D& right)
		{
			X += right.X;
			Y += right.Y;
		}

		Vector2D operator-(const Vector2D& right) const
		{
			return Vector2D(X - right.X, Y - right.Y);
		}

		Vector2D operator*(const T& scalar) const
		{
			return Vector2D(X * scalar, Y * scalar);
		}

		void operator*=(const T& scalar)
		{
			X *= scalar;
			Y *= scalar;
		}

		Vector2D operator/(const T& scalar) const
		{
			return Vector2D(X / scalar, Y / scalar);
		}

		void operator/=(const T& scalar)
		{
			X /= scalar;
			Y /= scalar;
		}

		Vector2D Rotate(float radians) const
		{
			auto cos = std::cos(radians);
			auto sin = std::sin(radians);
			return {
					cos * X - sin * Y,
					sin * X + cos * Y
			};
		}
	};

	using Vector2DUInt16 = Vector2D<uint16_t>;
	using Vector2DFloat  = Vector2D<float>;
}

