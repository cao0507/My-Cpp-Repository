#include <iostream>
#include <string.h>
//#include <string>

using namespace std;

int main(){
	//string name;
	char name[200] = "";
	cout << "What's your name?" << endl;
	cin >> name;
	//if (name.size() >= 2)
	if (strlen(name) >= 2)
		cout << "It's a valid name." << endl;
	else
		cout << "It's an invalid name." << endl;
	return 0;
}
