#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_size_ok(int size){
	const int max_size = 1024;
	if (size <= 0 || size > max_size){
		cerr << "pentagonal_func(): oops: invalid size: "
			 << size << "--can't fulfill request.\n";
		return false;
	}
	return true;
}

inline void pentagonal_func(vector<int> &elems, int size){
	if (!is_size_ok(size))
		return;
	for (int i = 1; i <= size; ++i){
		elems.push_back(i*(3*i-1)/2);
	}
}

template <typename elemType>
void display(const vector<elemType> & elems){
	for (auto &elem:elems)
		cout << elem << " ";
	cout << endl;
}

int main(){
	vector<int> elems;
	pentagonal_func(elems, 10);
	display(elems);
	vector<string> strs{"hello", "everyone,", "my", "name", "is", "CHL"};
	display(strs);
	return 0;
}
