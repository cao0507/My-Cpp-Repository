#include <iostream>
#include <vector>

using namespace std;

int main(){
	int arr[] = {1, 1, 3, 3, 3, 2, 4, 1, 1, 1, 0};
	int size = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr, arr+size);

	int previous = vec[0];
	for (vector<int>::iterator iter = vec.begin()+1; iter != vec.end();){
		if (previous == *iter){
			iter = vec.erase(iter);
		}
		else{
			previous = *iter;
			iter++;
		}
	}

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
