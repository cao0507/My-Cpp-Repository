#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main(){
	using namespace std::placeholders;
	int n = 5;
	std::vector<int> nums = {2, 3, 4, 5};
	//std::modulus<int> mod;
	//auto predicator = [&](int i) { return 0 == mod(n, i); };
	//auto is_divisible = std::any_of(nums.begin(), nums.end(), predicator);
	auto is_divisible = std::any_of(nums.begin(), nums.end(), std::bind(std::equal_to<int>(), std::bind(std::modulus<int>(), n, _1), 0));
	std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

	return 0;
}
