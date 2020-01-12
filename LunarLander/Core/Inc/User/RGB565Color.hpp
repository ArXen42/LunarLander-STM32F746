#pragma once

#include <cstddef>
#include <cstdint>

namespace LunarLander
{
	/// Represents RGB565 color
	class RGB565Color
	{
	public:
		static constexpr RGB565Color Black()
		{ return RGB565Color{0}; };

		static constexpr RGB565Color White()
		{ return RGB565Color{UINT16_MAX}; };

	private:
		static constexpr uint16_t RedMask   = 0b1111100000000000;
		static constexpr uint16_t GreenMask = 0b0000011111100000;
		static constexpr uint16_t BlueMask  = 0b0000000000011111;

	public:
		uint16_t Value;

		constexpr explicit RGB565Color(uint16_t value) : Value(value)
		{}

		constexpr RGB565Color(uint8_t r, uint8_t g, uint8_t b)
				: Value(r << 11u | g << 5u | b)
		{}

		[[nodiscard]] uint8_t GetR() const
		{ return Value & RedMask; }

		[[nodiscard]] uint8_t GetG() const
		{ return Value & GreenMask; }

		[[nodiscard]] uint8_t GetB() const
		{ return Value & BlueMask; }
	};

}

