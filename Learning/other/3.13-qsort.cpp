#include <iostream>
#include <cstdlib>

using namespace std;

#define max_size 5

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int arr[max_size];
	int n = 0;
	for (;n < 5;n++){
		cin >> arr[n];
	}
	qsort(arr, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
