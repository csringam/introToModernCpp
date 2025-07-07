#include <iostream>
#include <string>
#include <vector>
#include "Checking.h"

int main() {
	Checking cAcc("John Doe", 1000.0, 123456);

	std::cout << "Amount: " << cAcc.GetBalance() << std::endl;
}