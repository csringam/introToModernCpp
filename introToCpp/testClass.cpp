#include "testClass.h"

//Constructor and Destructor
testClass::testClass() = default;
testClass::~testClass() = default;

int testClass::testThis(int a, int b) {
	return a + b;
}
