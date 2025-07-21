#include <iostream>
#include <vector>
#include "recurSection.h"
#include "binarySearchRef.h"

const void printVector(const std::vector<int>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	return;
}

int main() {
	std::vector<int> test{ 1, 2, 3, 5, 6, 7, 9, 11, 13, 12 };
	int here = binarySearchExample(test, 5);
	if (here == -1) {
		std::cout << "Element not found." << std::endl;
	}
	else {
		std::cout << "Element found at index: " << here << std::endl;
	}
	return 0;
}