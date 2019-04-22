#include <iostream>
#include <string>
#include <map>
#include <functional>

int add(int a, int b) { return a + b; }
auto mod = [](int a, int b) { return a%b; };
struct Div { int operator() (int a, int b) const { return a/b; } };

std::map<std::string, std::function<int(int, int)>> binops = {
	{ "+", add },
	{ "-", std::minus<int>() },
	{ "*", [](int a, int b) { return a*b; } },
	{ "/", Div() },
	{ "%", mod }
};

int main(){
	while (std::cout << "Pls enter as: num operator num :\n", true){
		int lhs, rhs; 
		std::string op;
		std::cin >> lhs >> op >> rhs;
		std::cout << binops[op](lhs, rhs) << std::endl;
	}

	return 0;
}
