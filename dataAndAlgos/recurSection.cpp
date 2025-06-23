#include "recurSection.h"

void recurSection::recurCount(int n) {

	if (n > 0) {
		std::cout << n << " ";
		recurCount(n - 1);
	}
	return;
}

std::string recurSection::revString(std::string str) {
	std::string out;
	for (int i = str.length() - 1; i >= 0; i--) {
		out += str[i];
	}
	return out;
}

void recurSection::printFib(int n) {
	if (n <= 0) {
		std::cout << "Provide positive integer" << std::endl;
		return;
	}

	int firstNum = 0;
	std::cout << firstNum << " ";
	if (n == 1) {
		std::cout << std::endl;
		return;
	}

	int secNum = 1;

	// 0 1 1 2 3 5

	for (int i = 2; i <= n; i++) {
		std::cout << secNum << " ";

		int tempNum = secNum;
		secNum = firstNum + secNum;
		firstNum = tempNum;
	}

	std::cout << std::endl;
	return;
}

void recurSection::printFizzBuzz(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << i << " ";
		if (i % 3 == 0 && i % 5 == 0) {
			std::cout << "FizzBuzz ";
		}
		else if (i % 3 == 0) {
			std::cout << "Fizz ";
		}
		else if (i % 5 == 0) {
			std::cout << "Buzz ";
		}
		std::cout << std::endl;
	}
}

std::vector<int> recurSection::bubbleSort(std::vector<int> list) {
	std::vector<int> vec(list);
	int n = vec.size();
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			std::cout << n-i-1 << " " << j << " " << j + 1 << std::endl;
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break; // If no two elements were swapped, the array is sorted
		}
	}
	return {vec.begin(), vec.end()};
}