#include "recurSection.h"

void recurSection::recurCount(int n) {

	if (n > 0) {
		std::cout << n << " ";
		recurCount(n - 1);
	}
	return;
}