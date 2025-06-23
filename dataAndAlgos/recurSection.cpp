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