#pragma once

#include "Terrain.hpp"
#include "Camera.hpp"
#include "Lander.hpp"

namespace LunarLander
{
	class GameState
	{
	public:
		[[nodiscard]] const Terrain& GetTerrain() const
		{ return _terrain; }

		[[nodiscard]] const Camera& GetCamera() const
		{ return _camera; }

		void OnTick()
		{
			_lander.OnTick();
			_camera.Position = _lander.GetPosition();
			_camera.Zoom -= 0.01f; //test
		}

	private:
		Terrain _terrain{};
		Camera  _camera{{100, 100}, 1};
		Lander  _lander{{960, 200}, {0, 0}, 3.14 * 0};
	};
}

