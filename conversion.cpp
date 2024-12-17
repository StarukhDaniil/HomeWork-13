#pragma once
#include "conversion.h"

template <ConversionType type>
double convert(const double& value, const std::string& from, const std::string& to) {
	if constexpr (type == ConversionType::length) {
		if (from == "mm" && to == "m")
			return value * 1e-3f;
		else if (from == "m" && to == "mm")
			return value * 1e3f;
		else if (from == "m" && to == "km")
			return value * 1e-3f;
		else if (from == "km" && to == "m")
			return value * 1e3f;
	}
	else if constexpr (type == ConversionType::mass) {
		if (from == "g" && to == "kg")
			return value * 1e-3f;
		else if (from == "kg" && to == "g")
			return value * 1e3f;
		else if (from == "kg" && to == "t")
			return value * 1e-3f;
		else if (from == "t" && to == "kg")
			return value * 1e3f;
	}
	else if constexpr (type == ConversionType::temperature) {
		if (from == "K" && to == "C")
			return value - 273.0;
		else if (from == "C" && to == "K")
			return value + 273.0;
		else if (from == "C" && to == "F")
			return value * 1.8 + 32.0;
		else if (from == "F" && to == "C")
			return (value - 32.0) / 1.8;
	}
	else {
		throw "bad ConversionType";
	}
}
