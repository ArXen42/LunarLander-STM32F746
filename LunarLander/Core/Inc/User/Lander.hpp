#pragma once

#include "Vector2D.hpp"

namespace LunarLander
{
	class Lander
	{
	public:
		static constexpr size_t PhysicsTickRate      = 60;
		static constexpr float  PhysicsTickDeltaTime = 1.0f / PhysicsTickRate;
	public:
		Lander(const Vector2DFloat& position, const Vector2DFloat& speed, float rotation) : _position(position), _speed(speed), _rotation(rotation)
		{}

		[[nodiscard]] auto GetPosition() const
		{ return _position; }

		[[nodiscard]] auto GetRotation() const
		{ return _rotation; }

		void OnTick()
		{
			Vector2DFloat acceleration = (Vector2DFloat::Unit() * 10).Rotate(_rotation); // TODO: from user input
			acceleration *= 0;
			acceleration += Vector2DFloat::Down() * 1.625;
			acceleration *= PhysicsTickDeltaTime;

			_speed += acceleration;
			_position += _speed * PhysicsTickDeltaTime;
			// TODO: use tickrate
		}

	private:
		Vector2DFloat _position;
		Vector2DFloat _speed;
		float         _rotation;
	};
}
