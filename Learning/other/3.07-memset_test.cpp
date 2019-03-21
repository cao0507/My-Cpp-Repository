#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char buf[10];
	memset(buf, 65, 5);
	cout << buf << endl;
	return 0;
}
