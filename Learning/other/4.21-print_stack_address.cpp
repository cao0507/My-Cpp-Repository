#include <stdio.h>

void func(){
	char *p;
	p = (char *) &p;
	printf("p = %p\n", p);
	p += 36;
	*p = 100;
	printf("p = %p\n", p);
}

int main(){
	int a = 0;
	printf("&a = %p\n", &a);
	func();
	printf("%d\n", a);
	return 0;
}
