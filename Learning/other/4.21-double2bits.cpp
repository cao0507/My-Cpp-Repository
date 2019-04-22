#include <iostream>

using namespace std;

typedef union {
	double d;
	unsigned long u;
} temp;

int main(){
	temp t;
	t.d = 0.0;
	cout << t.d << endl;
	cout << t.u << endl;
	return 0;
}
