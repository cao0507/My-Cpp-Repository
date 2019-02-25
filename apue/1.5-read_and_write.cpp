#include <iostream>
#include <unistd.h>

#define 	BUFFSIZE 	4096

int main(){
	int 	n;
	char 	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if (write(STDOUT_FILENO, buf, n) != n){
			std::cerr << "write error.\n";
			return 0;
		}
	}
	if (n < 0){
		std::cerr << "read error.\n";
		return 0;
	}

	return 0;
}
