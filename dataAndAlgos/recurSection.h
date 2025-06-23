#pragma once
#include <iostream>
#include <string>
#include <vector>

class recurSection
{
public:
	void recurCount(int n);

	std::string revString(std::string str);

	void printFib(int n);

	void printFizzBuzz(int n);

	std::vector<int> bubbleSort(std::vector<int> list);
};

