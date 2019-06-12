#include <iostream>
#include <vector>

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

template <typename elemType>
void display(const vector<elemType> & elems){
	for (auto &elem:elems)
		cout << elem << " ";
	cout << endl;
}


const vector<int>* pentagonal_func(int size){
	static vector<int> elems;
	display(elems);
	if (!is_size_ok(size))
		return 0;
	for (int i = elems.size()+1; i <= size; ++i)
		elems.push_back(i*(3*i-1)/2);
	display(elems);
	return &elems;
}

int get_value(const vector<int> & elems, unsigned long pos){
	if (pos >= 0 && pos < elems.size())
		return elems[pos];
	else{
		cerr << "This position is invalid!" << endl;
		return -1;
	}
}

int main(){
	const vector<int> *pseq = pentagonal_func(5);
	pseq = pentagonal_func(10);
	pseq = pentagonal_func(15);
	pseq = pentagonal_func(6);
	if (!pseq){
		cerr << "error" << endl;
		return 0;
	}
	int val = get_value(*pseq, 6);
	cout << "The 6th number is: ";
	cout << val << endl;
}
