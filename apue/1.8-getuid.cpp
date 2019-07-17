#include <iostream>
#include <unistd.h>

int main(){
	std::cout << "uid = " << getuid() << std::endl;
	std::cout << "gid = " << getgid() << std::endl;
	return 0;
}
