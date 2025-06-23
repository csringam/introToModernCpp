#include <iostream>
#include "recurSection.h"

int main() {
	std::cout << "Finished intro of data and algos" << std::endl;
	
	recurSection testing;
	testing.recurCount(3);

	std::string input = "Hello";
	std::cout << "Rev string: " << testing.revString(input) << std::endl;

	int reqInt{ 0 };

	std::cout << "How many of fib sequence? ";
	std::cin >> reqInt;

	testing.printFib(reqInt);

	std::cout << "How many FizzBuzz? ";
	std::cin >> reqInt;

	testing.printFizzBuzz(reqInt);

	return 0;
}