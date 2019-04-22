#include <iostream>
#include <string>
#include <memory>

int main(){
	std::unique_ptr<std::string> p1(new std::string("hello"));
	//std::unique_ptr<std::string> p2 = p1;
	std::cout << *p1 << std::endl;
	*p1 = "world......";
	std::cout << *p1 << std::endl;
	return 0;
}
