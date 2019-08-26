#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
	int a = 0;
	if (fork() == 0){
		a = a+5;
		cout << a << &a << endl;
	}
	else{
		a = a-5;
		cout << a << &a << endl;
	}
}
