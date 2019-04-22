#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> alloc_vector(){
	return make_shared<vector<int>> ();
}

void assign_vector(shared_ptr<vector<int>> p){
	int n;
	while (cin >> n){
		p->push_back(n);
	}
}

void print_vector(shared_ptr<vector<int>> p){
	for (vector<int>::iterator iter = p->begin(); iter != p->end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}

int main(){
	auto p = alloc_vector();
	assign_vector(p);
	print_vector(p);
	return 0;
}
