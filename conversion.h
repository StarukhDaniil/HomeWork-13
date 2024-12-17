#pragma once
#include <string>

enum class ConversionType {
	length,
	mass,
	temperature
};

template <ConversionType type>
double convert(const double& value, const std::string& from, const std::string& to);

#include "conversion.cpp"