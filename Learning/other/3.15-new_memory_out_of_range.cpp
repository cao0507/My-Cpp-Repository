#include <iostream>

using namespace std;

int main(){
	int *ptr = new int[10];
	*ptr = 1;
	cout << *ptr << endl;
	*(ptr+1) = 3;
	cout << *(ptr+1) << endl;
	delete [] ptr;
	return 0;
}
