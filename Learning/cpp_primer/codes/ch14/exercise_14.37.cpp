#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual{
	int value;
	
public:
	IsEqual(int v): value(v) {}
	bool operator() (int elem){
		return elem == value;
	}
};

int main(){
	std::vector<int> nums = { 3, 2, 1, 4, 3, 7, 8, 6 };
	std::replace_if(nums.begin(), nums.end(), IsEqual(3), 0);
	for (auto n:nums)
		std::cout << n << " ";
	std::cout << std::endl;
	return 0;
}
