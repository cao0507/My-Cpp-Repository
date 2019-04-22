#include <iostream>
#include <string>
#include <cstring>
#include <memory>

int main(){
	const char *c1 = "hello ";
	const char *c2 = "world";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat(r, c1);
	strcat(r, c2);
	std::cout << r << std::endl;

	std::string s1 = "hello ";
	std::string s2 = "world";
	strcpy(r, (s1+s2).c_str());
	std::cout << r << std::endl;

	delete[] r;
	return 0;
}
