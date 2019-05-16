#include <iostream>

int main() {
	int b = 1;
	int * a;
	*a = b;
	std::cout << a << std::endl;
	return 0;
}
