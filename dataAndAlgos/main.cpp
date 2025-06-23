#include <iostream>
#include <vector>
#include "recurSection.h"

const void printVector(const std::vector<int>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	return;
}

int main() {
	std::cout << "Finished intro of data and algos" << std::endl;
	
	recurSection testing;
	testing.recurCount(3);

	std::string input = "Hello";
	std::cout << "Rev string: " << testing.revString(input) << std::endl;

	int reqInt{ 0 };
	/*
	std::cout << "How many of fib sequence? ";
	std::cin >> reqInt;

	testing.printFib(reqInt);

	std::cout << "How many FizzBuzz? ";
	std::cin >> reqInt;

	testing.printFizzBuzz(reqInt);
	*/
	std::vector<int> vec{ 0, 1, 4, 3, 5, 2 };

	vec = testing.bubbleSort(vec);

	printVector(vec);

	return 0;
}