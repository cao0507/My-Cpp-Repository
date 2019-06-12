#include <iostream>

using namespace std;

int main(){
	char acX[] = "abc";
	char acY[] = {'a', 'b', 'c'};
	char *szX = "abc";
	char *szY = "abc";

	//acX[0] = 'A';
	cout << &szX << endl;
	cout << &szY << endl;
	return 0;
}
