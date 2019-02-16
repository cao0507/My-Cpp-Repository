#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int>* create(){
	vector<int>* vec = new vector<int>;
	return vec;
	delete vec;
}

vector<int>* input(){
	vector<int>* vec = create();
	int val;
	while (cin >> val)
		(*vec).push_back(val);
	return vec;
	delete vec;
}

void print(){
	vector<int>* r = input();
	for (auto &v:*r){
		cout << v << " " << endl;
	}
	delete r;
}

int main(){
	print();
	return 0;
}
