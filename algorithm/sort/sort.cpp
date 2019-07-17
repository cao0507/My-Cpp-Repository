#include <iostream>
#include "sort.h"

void sort::swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void sort::print(const std::vector<int> &nums){
	for (std::vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); iter++){
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

