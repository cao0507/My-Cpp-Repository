#include <iostream>
#include <vector>

using namespace std;

vector<int>* alloc_vector(){
	return new vector<int>();
}

void assign_vector(vector<int> *p){
	int n;
	while (cin >> n){
		p->push_back(n);
	}
}

void print_vector(vector<int> *p){
	for (vector<int>::iterator iter = p->begin(); iter != p->end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}

int main(){
	auto p = alloc_vector();
	assign_vector(p);
	print_vector(p);
	delete p;
	return 0;
}
