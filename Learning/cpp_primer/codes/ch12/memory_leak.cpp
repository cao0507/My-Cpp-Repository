#include <iostream>

using namespace std;

void alloc_memory(char* p, int num){
	p = new char[num];
}

int main() {
	char* str = NULL;
	alloc_memory(str, 10);
	cout << "Memory leak test." << endl;
	return 0;
}
