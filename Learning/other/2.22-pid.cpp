#include <unistd.h>
#include <iostream>

int main() {
	std::cout << getpid() << " " << getppid();
	std::cout << std::endl;
	std::cout << getuid() << " " << getgid();
	std::cout << std::endl;
	return 0;
}
