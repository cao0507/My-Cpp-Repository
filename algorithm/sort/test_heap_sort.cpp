#include "sort.h"

int main(){
	int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
	vector<int> nums(arr, arr+10);
	Heap_sort s;
	s.heap_sort(nums);
	s.print(nums);
	return 0;
}
