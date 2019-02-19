#include <memory>
#include <iostream>
#include <vector>

using namespace std;

shared_ptr<vector<int>> create(){
	shared_ptr<vector<int>> p = make_shared<vector<int>>();
	return p;
}

shared_ptr<vector<int>> input(){
	shared_ptr<vector<int>> q = create();
	int val;
	while (cin >> val){
		(*q).push_back(val);
	}
	return q;
}

void print(){
	shared_ptr<vector<int>> r = input();
	for (auto &v:*r)
		cout << v << " " << endl;
}

int main(){
	print();
	return 0;
}
