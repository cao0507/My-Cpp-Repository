#include <iostream>

using namespace std;

int main(){
	int N, n = 0;
	cin >> N;

	int re = 1024 - N;
	n += re/64;
	re = re%64;
	n += re/16;
	re = re%16;
	n += re/4;
	re = re%4;
	n += re;
	cout << n << endl;
	return 0;
}
