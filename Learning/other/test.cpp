#include <iostream>
#include <string>

using namespace std;

bool cmp(int a, int b){
	cout << to_string(a) << " " << to_string(b) << endl;
	if (to_string(a)+to_string(b) < to_string(b)+to_string(a))
		return true;
	else 
		return false;
}

int main(){
	int a = 32, b = 321;
	if (cmp(a, b))
		cout << "a < b" << endl;
	else
		cout << "a > b" << endl;
	return 0;
}
