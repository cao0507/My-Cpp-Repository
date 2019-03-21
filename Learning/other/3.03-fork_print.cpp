#include <iostream>
#include <unistd.h>

int main(){
	fork();
	std::cout << "hello\n";
	return 0;
}
