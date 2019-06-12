#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int>* create() {
	vector<int>* p = new vector<int>;
	return p;
	delete p;
}

vector<int>* input() {
	vector<int>* q = create();
	int val;
	while (cin >> val)
	{
		(*q).push_back(val);
	}
	return q;
	delete q;
}

void print() {
	vector<int>* r = input();
	for (auto &v : *r) {
		cout << v << " " << endl;
	}
	delete r;
}

int main() {
	print();
	return 0;
}