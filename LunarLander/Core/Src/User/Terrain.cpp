#include "User/Terrain.hpp"

namespace LunarLander
{
	void Terrain::MidpointDisplacement1D(size_t l, size_t r, float roughness,
	                                     std::mt19937& mt, std::uniform_real_distribution<float>& dist)
	{
		const size_t delta = r - l;
		if (delta > 1)
		{
			_heightmap[(l + r) / 2] = static_cast<float>(_heightmap[l] + _heightmap[r]) / 2 +
			                          dist(mt) * delta * roughness;

			MidpointDisplacement1D(l, (l + r) / 2, roughness, mt, dist);
			MidpointDisplacement1D((l + r) / 2, r, roughness, mt, dist);
		}
	}

	void Terrain::GenerateHeightmap(float startHeight, float endHeight, float roughness)
	{
		std::random_device                    rd;
		std::mt19937                          mt(rd());
		std::uniform_real_distribution<float> dist(-0.5, 0.5);

		_heightmap[0]                 = startHeight;
		_heightmap[TerrainLength - 1] = endHeight;

		// TODO: more interesting terrain
		MidpointDisplacement1D(0, TerrainLength - 1, roughness / TerrainLength, mt, dist);
		MidpointDisplacement1D(0, TerrainLength - 1, roughness / TerrainLength, mt, dist);
	}
}
