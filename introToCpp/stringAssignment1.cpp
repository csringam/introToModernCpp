#include <iostream>
#include <string>
#include <memory>

std::string ToUpper(const std::string& str) {
	std::string res;
	for (char c : str) {
		res += std::toupper(c);
	}
	return res;
}

std::string ToLower(const std::string& str) {
	std::string res;
	for (char c : str) {
		res += std::tolower(c);
	}
	return res;
}

void demoString1() {
	std::string input;
	std::string output;

	std::cout << "Enter string to upper: ";
	std::getline(std::cin, input);
	std::cout << "Uppercase: " << ToUpper(input) << std::endl;

	input.clear();
	output.clear();

	std::cout << "Enter string to lower: ";
	std::getline(std::cin, input);
	std::cout << "Lowercase: " << ToLower(input) << std::endl;

	input.clear();
	output.clear();
}