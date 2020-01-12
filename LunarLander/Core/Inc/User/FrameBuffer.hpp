#pragma once

#include <array>
#include "RGB565Color.hpp"
#include "Vector2D.hpp"

/// Provides access to framebuffer.
class FrameBuffer
{
public:
	static constexpr uint16_t Width  = 480;
	static constexpr uint16_t Height = 272;

	static constexpr size_t MemorySize = Width * Height * (5 + 6 + 5) / 16;

public:
	static std::array<uint16_t, MemorySize> Memory;

	static void Fill(RGB565Color color)
	{
		// TODO: DMA2D
		for (size_t i = 0; i < MemorySize; i++)
		{
			Memory[i] = color.Value;
		}
	}

	static void SetPixel(const Vector2DUint16 &pos, RGB565Color color)
	{
		Memory[pos.Y * Width + pos.X] = color.Value;
	}

	static void DrawLine(RGB565Color color, const Vector2DUint16 &start, const Vector2DUint16 &end)
	{
	}
};