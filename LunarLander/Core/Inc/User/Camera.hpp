#pragma once

#include "Vector2D.hpp"

namespace LunarLander
{
	class Camera
	{
	public:
		Vector2DFloat Position;

		Camera(const Vector2DFloat& position, float zoom)
				: Position(position), Zoom(zoom)
		{}

		float Zoom;
	};
}

