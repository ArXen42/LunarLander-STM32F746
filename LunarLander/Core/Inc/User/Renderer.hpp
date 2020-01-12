#pragma once

#include "GameState.hpp"

namespace LunarLander
{
	class Renderer
	{
	public:
		static void Render(const GameState& gameState)
		{
			FrameBuffer::Fill(RGB565Color::Black());

			auto& camera                        = gameState.GetCamera();
			auto& terrain                       = gameState.GetTerrain();

			Vector2DFloat viewportWorldSize{FrameBuffer::Width / camera.Zoom, FrameBuffer::Height / camera.Zoom};
			Vector2DFloat viewportWorldSizeHalf = viewportWorldSize / 2;

			Vector2DFloat viewportWorldBottomLeft = camera.Position - viewportWorldSizeHalf;
			Vector2DFloat viewportWorldTopRight   = camera.Position + viewportWorldSizeHalf;

			for (uint16_t i = 0; i < LunarLander::Terrain::TerrainLength; ++i)
			{
				float worldX = i;
				float worldY = terrain.GetHeightmap()[worldX];

				bool isOutOfBounds = worldX < viewportWorldBottomLeft.X
				                     || worldX > viewportWorldTopRight.X
				                     || worldY < viewportWorldBottomLeft.Y
				                     || worldY > viewportWorldTopRight.Y;

				if (isOutOfBounds)
					continue;

				uint16_t viewportX = (worldX - viewportWorldBottomLeft.X) * FrameBuffer::Width / viewportWorldSize.X;
				uint16_t viewportY = (worldY - viewportWorldBottomLeft.Y) * FrameBuffer::Height / viewportWorldSize.Y;

				FrameBuffer::SetPixel({viewportX, viewportY}, RGB565Color::White());
			}
		}
	};
}
