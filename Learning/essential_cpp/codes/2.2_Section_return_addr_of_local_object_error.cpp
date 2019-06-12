#include <iostream>

using namespace std;

int* func(){
	int val = 0;
	return &val;
}

int main(){
	int* p = func();
	cout << *p << endl;
	return 0;
}
