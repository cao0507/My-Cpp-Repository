#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> vec = {"HOME", "LANG", "PWD", "LOGNAME", "SHELL", "PATH"};
	for (unsigned long i = 0; i < vec.size(); i++){
		cout << vec[i] << " = " << getenv(vec[i].c_str()) << endl;
	}
	cout << endl;
	return 0;
}
