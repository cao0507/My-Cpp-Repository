#include <iostream>
#include <string>
#include <stack>


using namespace std;



int main(){
	int n;
	string str;
	cin >> n;
	cin >> str;

	stack<char> Stack;
	for (auto c:str){
		if (Stack.empty())
			Stack.push(c);
		else if (c == Stack.top())
			Stack.push(c);
		else
			Stack.pop();
	}

	cout << Stack.size();
	return 0;
}
