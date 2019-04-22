#include <iostream>

void fun(){
	int *p = (int*)(&p+1);
	p -= 1;
	*p = 100;
}

int main(){
	int a = 10;
	fun();
	std::cout << a << std::endl;
	return 0;
}
