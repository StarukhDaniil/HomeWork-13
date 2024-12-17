#pragma once
#include <string>

enum class ConversionType {
	length,
	mass,
	temperature
};

template <ConversionType type>
double convert(const double& value, std::string from, std::string to);

#include "conversion.cpp"