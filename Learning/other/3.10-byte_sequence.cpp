#include <iostream>

using namespace std;

int main(){
	short val = 0x0102;
	char *p = (char *) &val;

	if (*p == 1 && *(p+1) == 2)
		cout << "big-endian" << endl;
	else if (*p == 2 && *(p+1) == 1)
		cout << "little-endian" << endl;
	return 0;
}
