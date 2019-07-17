#include <iostream>
#include <vector>

using namespace std;

int main(){
	int arr[] = {100, 300, 500};
	vector<int> vec(arr, arr+3);
	vector<int>::iterator iter = vec.begin();
	vector<int>::iterator iterE = vec.end();
	vector<int>::iterator iter1 = iter+1;
	vector<int>::iterator iter2 = iter+2;
	vector<int>::iterator iter3 = vec.erase(iter1);
	cout << *iter << endl;
	cout << *iter1 << endl;
	cout << *iter2 << endl;
	cout << *iter3 << endl;
	cout << *(iterE-1) << endl;
	cout << *(iterE-2) << endl;
	cout << *(iterE-3) << endl;

	return 0;
}
