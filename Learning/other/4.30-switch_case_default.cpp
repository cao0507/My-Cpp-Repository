#include <iostream>

using namespace std;

int main(){
	int c = 0, i;
	for (i = 1; i < 3; i++){
		switch(i){
			default:
				c += 5;

			case 3:
				c++;
				break;

			case 4:
				c += 2;
				break;
		}
	}
	cout << "c = " << c << endl;
	cout << "i = " << i << endl;
	return 0;
}
