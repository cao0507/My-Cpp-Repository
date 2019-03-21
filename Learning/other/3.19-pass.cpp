#include <stdio.h>

void pass(){
	int y;
	printf("%ld", (long)&y);
	//*(&y+32*8) = 456;
	//*(((long)(&y))-32) = 456;
}

int main(){
	int x = 123;
	printf("%ld", (long)&x);
	printf("%d\n", x);
	pass();
	printf("%d\n", x);
	return 0;
}
