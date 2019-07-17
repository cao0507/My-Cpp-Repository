#include <iostream>
#include <string>
#include "4.1-Stack.h"

using namespace std;

int main(){
	Stack s;
	string str;
	while (cin >> str){
		s.push(str);
	}

	s.pop(str);
	cout << "Pop the last element: " << str << endl;

	cout << "Please input the string you want to search: " << endl;
	cin.clear();

	cin >> str;
	if (s.find(str)){
		int num = s.count(str);
		cout << "Search Successfully!!!" << endl;
		cout << "The number of the string is: " << num << endl;
	}

	s.print();
	return 0;
}
