#include <iostream>

using namespace std;

int main(){
	int val = 2;
	switch (val){
		case 1:
			cout << "first line" << endl;
			//break;

		case 2:
			cout << "second line" << endl;
			//break;

		case 3:
			cout << "third line" << endl;
			break;

		case 4:
			cout << "fourth line" << endl;
			//break;

		default:
			cout << "the last line" << endl;
			//break;
	}
	return 0;
}
