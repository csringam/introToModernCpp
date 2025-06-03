#include <iostream>
#include "testClass.h"

int main() {
	std::cout << "Hello, World!" << std::endl;
	testClass testObj;

	int a = 1;
	int b = 2;

	int c = testObj.testThis(a, b);

	std::cout << "The result of testThis is: " << c << std::endl;
	return 0;
}