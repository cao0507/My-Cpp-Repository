#include <stdio.h>

int main(){
	#ifndef __cplusplus
		printf("a C program\n");
	#else
		printf("a C++ program\n");
	#endif
	return 0;
}
