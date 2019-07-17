#include <iostream>

using namespace std;

int main(){
	char a[] = {'a', 'b', 'c'};
	char b[] = {"abcd"};
	cout << *a << " "<< *(a+1) << " " << *(a+2) << endl;
	cout << *b <<" " << *(b+1) << " " << *(b+2) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	return 0;
}
