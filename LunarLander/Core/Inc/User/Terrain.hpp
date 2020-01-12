#pragma once

#include <random>
#include "FrameBuffer.hpp"

namespace LunarLander
{
	class Terrain
	{
	public:
		static constexpr size_t TerrainLength = FrameBuffer::Width * 4;

	public:
		Terrain()
		{
			GenerateHeightmap(20, 80, 500);
		}

		const std::array<uint16_t, TerrainLength>& GetHeightmap()
		{ return _heightmap; }

	private:
		std::array<uint16_t, TerrainLength> _heightmap{};

		void GenerateHeightmap(float startHeight, float endHeight, float roughness);

		void MidpointDisplacement1D(size_t l, size_t r, float roughness,
		                            std::mt19937& mt, std::uniform_real_distribution<float>& dist);
	};
}
