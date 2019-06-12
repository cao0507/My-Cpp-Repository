#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &vec){
	for (auto &v:vec)
		cout << v << " ";
	cout << endl;
}

void swap(int &v1, int &v2){
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

void bubble_sort(vector<int> &vec){
	for (unsigned long i = 0; i < vec.size()-1; ++i){
		for (unsigned long j = i + 1; j < vec.size(); ++j){
			if (vec[i] > vec[j])
				swap(vec[i], vec[j]);
		}
	}
}

int main(){
	vector<int> vec = {8, 34, 3, 13, 1, 21, 5, 2};
	display(vec);
	bubble_sort(vec);
	display(vec);
	return 0;
}
