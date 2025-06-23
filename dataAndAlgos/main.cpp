#include <iostream>
#include "recurSection.h"

int main() {
	std::cout << "Finished intro of data and algos" << std::endl;
	
	recurSection testing;
	testing.recurCount(3);

	std::string input = "Hello";
	std::cout << "Rev string: " << testing.revString(input) << std::endl;

	int fibReq{ 0 };

	std::cout << "How many of fib sequence? ";
	std::cin >> fibReq;
	std::cout << std::endl;

	testing.printFib(fibReq);

	return 0;
}