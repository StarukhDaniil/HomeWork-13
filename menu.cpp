#include "menu.h"

#include "conversion.h"
#include <string>
#include <iostream>
#include <algorithm>

double getDoubleInput(const std::string& prompt) {
	double input;
	if (prompt != "")
		std::cout << prompt;

	while (true) {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<uint16_t>::max(), '\n');
			std::cout << "You entered something incorrect, try again: ";
		}
		else
			return input;
	}
}

void menu() {
	std::string type;
	std::string from;
	std::string to;
	double value;

	std::cout << "Select type of the conversion(type 0 to exit)" << std::endl;
	std::cout << "Length, mass or temperature:" << std::endl;
	std::cout << "Your choice: ";
	std::cin >> type;
	
	std::transform(type.begin(), type.end(), type.begin(), tolower);
	system("cls");
	
	if (type == "length") {
		std::cout << "Select what to convert from" << std::endl;
		std::cout << "mm, m or km:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> from;

		std::cout << "Select what to convert to" << std::endl;
		std::cout << "mm, m or km:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> to;

		value = getDoubleInput("Enter value: ");
		std::cout << "Result: " << convert<ConversionType::length>(value, from, to) << std::endl;
	}
	else if (type == "mass") {
		std::cout << "Select what to convert from" << std::endl;
		std::cout << "g, kg or t:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> from;

		std::cout << "Select what to convert to" << std::endl;
		std::cout << "g, kg or t:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> to;

		value = getDoubleInput("Enter value: ");
		std::cout << "Result: " << convert<ConversionType::mass>(value, from, to) << std::endl;
	}
	else if (type == "temperature") {
		std::cout << "Select what to convert from" << std::endl;
		std::cout << "K, C, or F:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> from;

		std::cout << "Select what to convert to" << std::endl;
		std::cout << "K, C, or F:" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> to;

		value = getDoubleInput("Enter value: ");
		std::cout << "Result: " << convert<ConversionType::temperature>(value, from, to) << std::endl;
	}
	else if (type == "0")
		exit(0);
	std::cout << std::endl;
	std::cout << "Press enter to continue" << std::endl;
	std::cin.get();
	std::cin.ignore(std::numeric_limits<uint16_t>::max(), '\n');
	system("cls");
}