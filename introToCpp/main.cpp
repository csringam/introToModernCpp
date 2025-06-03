#include <iostream>
#include "testClass.h"
#include "searchAlgo.h"

int main() {
	std::cout << "Hello, World!" << std::endl;
	testClass testObj;

	int a = 1;
	int b = 2;

	int c = testObj.testThis(a, b);

	std::cout << "The result of testThis is: " << c << std::endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	searchAlgo searchObj;

	int foundIdx = searchObj.BST(arr, 2);

	std::cout << "Found 2 at index: " << foundIdx << std::endl;

	return 0;
}