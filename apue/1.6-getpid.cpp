#include <iostream>
#include <unistd.h>

int main(){
	std::cout << "the process ID(PID) is: " << getpid() << std::endl;
	std::cout << "the ID of parent process(PPID) is: " << getppid() << std::endl;
	return 0;
}
