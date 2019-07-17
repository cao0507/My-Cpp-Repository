#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
public:
	bool push(const string&);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty();
	bool full();
	int size() { return _stack.size(); };
	void print();

	bool find(string &elem);
	int count(string &elem);

private:
	vector<string> _stack;
};

bool Stack::push(const string &elem){
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}

bool Stack::pop(string &elem){
	if (empty())
		return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::peek(string &elem){
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}

bool Stack::empty(){
	if (_stack.size() == 0)
		return true;
	return false;
}

bool Stack::full(){
	if (_stack.size() == _stack.max_size())
		return true;
	return false;
}

void Stack::print(){
	auto it = _stack.begin();
	for ( ; it != _stack.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

bool Stack::find( string &elem ){
	for ( auto &v:_stack ){
		if ( v == elem )
			return true;
	}
	return false;
}

int Stack::count( string &elem ){
	int num = 0;
	for ( auto &v:_stack ){
		if ( v == elem )
			num++;
	}
	return num;
}
