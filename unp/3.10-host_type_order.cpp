#include <iostream>

#define CPU_VENDOR_OS "x86_64-unknown-linux-gnu"

using namespace std;

int main(){
	union {
		short s;
		char c[sizeof(short)];
	} un;

	un.s = 0x0102;
	cout << un.c[0] << " " << un.c[1] << endl;
	cout << CPU_VENDOR_OS << ": " << endl;
	if ( sizeof(short) == 2 ){
		if ( un.c[0] == 1 && un.c[1] == 2 )
			cout << "big-endian" << endl;
		else if ( un.c[0] == 2 && un.c[1] == 1 )
			cout << "little-endian" << endl;
		else
			cout << "unknown" << endl;
	}
	else
		cout << "sizeof(short) = " << sizeof(short) << endl;
	return 0;
}
