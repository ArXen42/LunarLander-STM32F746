#pragma once

#include <array>
#include "RGB565Color.hpp"
#include "Vector2D.hpp"
#include "dma2d.h"

namespace LunarLander
{
	/// Provides access to framebuffer.
	class FrameBuffer
	{
	public:
		static constexpr uint16_t HalfWidth  = 240;
		static constexpr uint16_t HalfHeight = 136;
		static constexpr uint16_t Width      = HalfWidth * 2;
		static constexpr uint16_t Height     = HalfHeight * 2;

		static constexpr size_t MemorySize = Width * Height * (5 + 6 + 5) / 16;

	public:
		static std::array<uint16_t, MemorySize> Memory;

		static void Fill(RGB565Color color)
		{
			HAL_DMA2D_Start(&hdma2d, color.Value, reinterpret_cast<uint32_t>(Memory.data()), Width, Height);
			HAL_DMA2D_PollForTransfer(&hdma2d, 1000);
		}

		static void SetPixel(const Vector2DUInt16& pos, RGB565Color color)
		{
			Memory[(Height - pos.Y - 1) * Width + pos.X] = color.Value;
		}

		static void DrawLine(RGB565Color color, const Vector2DUInt16& start, const Vector2DUInt16& end)
		{
		}
	};
}

