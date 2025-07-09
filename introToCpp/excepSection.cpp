#include <iostream>
#include <string>

void throwExcep(int x) {
	if (x < 2) {
		throw std::out_of_range("x must be at least 2");
	}
	return;
}

int testingHere() {
	try {
		throwExcep(1);
		return 0;
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Caught unknown exception" << std::endl;
	}
}