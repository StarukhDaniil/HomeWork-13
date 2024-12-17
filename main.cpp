#include <iostream>
#include "conversion.h"

int main() {
	std::cout << convert<ConversionType::mass>(200.0, "kg", "g") << std::endl;
	return 0;
}