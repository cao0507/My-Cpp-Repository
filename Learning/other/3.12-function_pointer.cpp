#include <iostream>

using namespace std;

int min(int x, int y){
	if (x > y)
		return y;
	return x;
}

int main(){
	int (*f) (int x, int y);
	f = &min;
	cout << (*f)(10, 20) << endl;
	return 0;
}
