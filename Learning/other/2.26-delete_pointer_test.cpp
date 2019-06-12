#include <iostream>

using namespace std;

int main(){
	int *p = new int(1);
	*p = 3;
	cout << *p << endl;
	delete p;
	cout << *p << endl;

	int *p1 = new int(1);
	cout << *p1 << endl;
	cout << *p << endl;

	*p1 = 5;
	cout << *p1 << endl;
	cout << *p << endl;

	*p = 7;
	cout << *p1 << endl;
	cout << *p << endl;
	return 0;
}
