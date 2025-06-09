#include "Integer.h"
#include <iostream>
#include <memory>
class IntPtr {
	Integer* m_p;
public:
	IntPtr(Integer* p) :m_p(p) {

	}
	~IntPtr() {
		delete m_p;
	}
	Integer* operator ->() {
		return m_p;
	}
	Integer& operator *() {
		return *m_p;
	}
};
void CreateInteger() {
	std::unique_ptr<Integer> p(new Integer);
	//auto p2(p);
	(*p).SetValue(3);
	//std::cout << p->GetValue() << std::endl; 
}
void Process(Integer val) {

}

int main() {
	Integer a(3);
	/*auto b(std::move(a));
	std::cout << a << std::endl;*/
	Process(std::move(a));
	return 0;
}

/*
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
}*/