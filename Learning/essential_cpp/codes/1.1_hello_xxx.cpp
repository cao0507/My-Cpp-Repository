#include <iostream>

using namespace std;

int main(){
	string first_name;
	string last_name;
	string name;
	cout << "Please input your first name and last name:" << endl;
	cin >> first_name >> last_name;
	name = first_name + last_name;
	cout << "Hello, " << name << endl;
	return 0;
}

