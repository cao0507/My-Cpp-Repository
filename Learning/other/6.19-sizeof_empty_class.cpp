#include <iostream>

class empty
{};

int main()
{
	empty e;
	std::cout << sizeof(e) << std::endl;
	return 0;
}
