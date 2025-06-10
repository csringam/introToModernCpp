#include <iostream>

class Printer {
	std::weak_ptr<int> pValue{};
public:
	void setValue(std::weak_ptr<int> p) {
		pValue = p;
	}

	void Print() {
		if(pValue.expired()) {
			std::cout << "Pointer is expired." << std::endl;
			return;
		}
		auto sp = pValue.lock();
		std::cout << "Value: " << *sp << std::endl;
	}
};

class Student;
class Work {
public:
	std::shared_ptr<Student> pStudent;
	Work() {
		std::cout << "Work()" << std::endl;
	}
	~Work() {
		std::cout << "~Work()" << std::endl;
	}
};

class Student {
public:
	std::weak_ptr<Work> pWork;
	Student() {
		std::cout << "Student()" << std::endl;
	}
	~Student() {
		std::cout << "~Student()" << std::endl;
	}
};

void dynaArrayDemo() {
	std::unique_ptr<int[]> pArray{ new int[5] {1,2,3,4,5} };
	pArray[0] = 10;
	std::cout << "Array[0]: " << pArray[0] << std::endl;
}

class Point {
public:
	Point(int x, int y) {

	}
};

void makeFuncDemo() {
	// Cannot use deleter with make_unique for non-pointer types
	auto p = std::make_unique<int>(42);
	std::cout << "Value: " << *p << std::endl;

	auto pPoint = std::make_unique<Point>(1, 2);

	auto pArray = std::make_unique<int[]>(5);
	pArray[0] = 5;

	auto pShared = std::make_shared<int>(20);
	auto pPointShared = std::make_shared<Point>(3, 4);
}

void runDemosWeakPtr() {
	std::shared_ptr<Student> stu{ new Student{} };
	std::shared_ptr<Work> work{ new Work{} };

	stu->pWork = work; // Student holds a weak pointer to Work
	work->pStudent = stu; // Work holds a shared pointer to Student

	dynaArrayDemo();
	makeFuncDemo();
}