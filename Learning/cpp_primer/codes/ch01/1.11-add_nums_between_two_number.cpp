#include <iostream>

int main(){
	int first, second;
	std::cin >> first >> second;
	int sum = 0;
	int begin = (first < second)? first : second;
	int end = (first < second)? second : first;
	while (begin <= end){
		sum += begin;
		++begin;
	}
	std::cout << sum;
	return 0;
}
