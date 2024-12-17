#pragma once
#include "conversion.h"
#include "algorithm"

#pragma warning(disable: 4715)

template <ConversionType type>
double convert(const double& value, std::string from, std::string to) {
	std::transform(from.begin(), from.end(), from.begin(), tolower);
	std::transform(to.begin(), to.end(), to.begin(), tolower);
	if (from == to)
		return value;

	if constexpr (type == ConversionType::length) {
		if (from == "mm" && to == "m")
			return value * 1e-3;
		else if (from == "m" && to == "mm")
			return value * 1e3;
		else if (from == "m" && to == "km")
			return value * 1e-3;
		else if (from == "km" && to == "m")
			return value * 1e3;
		else if (from == "mm" && to == "km")
			return value * 1e-6;
		else if (from == "km" && to == "mm")
			return value * 1e6;
	}
	else if constexpr (type == ConversionType::mass) {
		if (from == "g" && to == "kg")
			return value * 1e-3;
		else if (from == "kg" && to == "g")
			return value * 1e3;
		else if (from == "kg" && to == "t")
			return value * 1e-3;
		else if (from == "t" && to == "kg")
			return value * 1e3;
		else if (from == "g" && to == "t")
			return value * 1e-6;
		else if (from == "t" && to == "g")
			return value * 1e6;
	}
	else if constexpr (type == ConversionType::temperature) {
		if (from == "k" && to == "c")
			return value - 273.0;
		else if (from == "c" && to == "k")
			return value + 273.0;
		else if (from == "c" && to == "f")
			return value * 1.8 + 32.0;
		else if (from == "f" && to == "c")
			return (value - 32.0) / 1.8;
		else if (from == "k" && to == "f")
			return value * 1.8 - 459.4;
		else if (from == "f" && to == "k")
			return (value - 32.0) / value / 1.8 + 255.2;
	}
	else {
		throw "bad ConversionType";
	}
}
