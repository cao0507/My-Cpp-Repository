#include <iostream>

using namespace std;

struct S{
	union{
		char str[5];
		short b[2];
	}un; /* union是按照short来补齐的，而不是按照外部的float */
	char str2[2]; /* str2可以直接放在un的后面，而不需和按照float的对齐方式 */
	float f;
}ss;

int main(){
	cout << sizeof(ss) << endl;
	return 0;
}
